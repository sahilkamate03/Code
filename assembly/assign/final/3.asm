; Assignment Number : 03
; Problem defination : Write an ALP program to perform basic operation.
; Name : Shivanshu Tiwari
; Roll Number : 7252
; Date : 12/04/2022

%macro input 2
	mov rax, 0		; System call for read
	mov rdi, 0		; defining stream i.e stdin
	mov rsi, %1	; rsi point to buffer	
	mov rdx, %2	; rdi stores buffer length
	syscall
%endmacro

%macro print 2
	mov rax, 1		; system call for write
	mov rdi, 1		; defining stream i.e stdout
	mov rsi, %1	; rsi point to buffer	
	mov rdx, %2	; rdi stores buffer length
	syscall
%endmacro

section .data			                 
	mssg_sel db "--> Select an option from the menu :"
	mssg_sel_len: equ $ - mssg_sel

	mssg_menu db "--> Menu : <--", 10, "1. Addition", 10, "2. Substraction", 10, "3. Multiplication", 10, "4. Division", 10, "5. Exit", 10
	mssg_menu_len: equ $ - mssg_menu
	
	
	mssg1 db "Enter your 1st operand: "			
	mssg1_len: equ $-mssg1
		
	mssg2 db "Enter your 2nd operand: "		
	mssg2_len: equ $-mssg2

	mssg3 db "Enter the divisor : "			
	mssg3_len: equ $-mssg3
	
	mssg4 db "Enter the dividend : "			
	mssg4_len: equ $-mssg4	
	
	mssg_sum db "Sum of given operands : "
	mssg_sum_len: equ $-mssg_sum

	mssg_sub db "Substraction of given operands : "
	mssg_sub_len: equ $-mssg_sub

	mssg_mul db "Multiplication of given operands : "
	mssg_mul_len: equ $-mssg_mul

	mssg_quot db "Quotient : "
	mssg_quot_len: equ $-mssg_quot

	mssg_rem db "Remainder : "
	mssg_rem_len: equ $-mssg_rem
	
	space db " "	
	newline db 10						
	
section .bss			                
	num1 resb 17		                
	num2 resb 9
	hex1 resq 1		                  
	hex2 resq 1		                   
	divisor resd 1		             
	temp resb 16		                
	choice resb 2	
	
section .text						  
	global _start				
_start: 					   
	menu:
		print mssg_menu, mssg_menu_len	
		print newline, 1
		print mssg_sel, mssg_sel_len	
		input choice, 2
		
		case_1:
			cmp byte[choice], 31h		
			jne case_2
			call addition			 
			jmp menu
		case_2:	
			cmp byte[choice], 32h
			jne case_3
			call substraction		  
			jmp menu
		case_3:
			cmp byte[choice], 33h
			jne case_4
			call multiplication		      
			jmp menu
		case_4:
			cmp byte[choice], 34h
			jne case_5
			call division
			jmp menu
		case_5:
			cmp byte[choice], 35h
			je Exit			
			print mssg0, mssg0_len
			print newline, 1
			jmp menu
			
	Exit:
	mov rax, 60					       
	mov rdi, 0
	syscall
	
addition:
	print newline, 1
	print mssg1, mssg1_len
	input num1, 17			                  
	
	call ascii_hex64		              
	mov [hex1], rbx		                   
	
	print mssg2, mssg2_len
	input num1, 17			                  
	
	call ascii_hex64
	mov [hex2], rbx		                       
	
	mov rax, [hex1]		                        
	add rax, [hex2]		                   
	mov rbx, rax 			                 
	
	print mssg_sum, mssg_sum_len
	call display64			                 
	print newline, 1
	ret

substraction:
	print newline, 1
	print mssg1, mssg1_len
	input num1, 17			                  
			
	call ascii_hex64		                
	mov [hex1], rbx		                   
	
	print mssg2, mssg2_len
	input num1, 17			                
	
	call ascii_hex64
	mov [hex2], rbx		                    
	
	mov rax, [hex1]		                    
	sub rax, [hex2]		                  
	mov rbx, rax			                
	
	print mssg_sub, mssg_sub_len
	call display64			                  
	print newline, 1
	ret

multiplication:
	print newline, 1
	print mssg1, mssg1_len
	input num1, 17			                 
			
	call ascii_hex64		                 
	mov [hex1], rbx		                    
	
	print mssg2, mssg2_len
	input num1, 17			                 
	
	call ascii_hex64
	mov [hex2], rbx		                       
	
	mov rax, [hex1]		                        
	mov rbx, [hex2]		                     
	
	mul rbx			                       
	
	push rax
	push rdx
	print mssg_mul, mssg_mul_len	 
           
	pop rdx	
	mov rbx, rdx
	call display64			              
	print space, 1
	
	pop rax
	mov rbx, rax
	call display64			                    
	print newline, 1

	ret
	
division:
	print newline, 1
	print mssg4, mssg4_len		                
	input num1, 17
	
	print mssg3, mssg3_len  	               
	input num2, 9
	
	call ascii_hex32		               
	mov [divisor], rbx		                    
	
	mov rsi, num1			                    
	mov rdi, num2			                   	
	cld				                      
	mov rcx, 8
	rep movsb			                 
	call ascii_hex32		                 	
	mov edx, ebx			                   
	
	mov rsi, num1+8		                     
	mov rdi, num2			                    
	
	cld				                            
	mov cx, 8
	rep movsb			                       
	
	push rdx
	call ascii_hex32		                   
	pop rdx
	mov eax, ebx			                   
	
	mov ebx, [divisor]		                   
	div ebx			                            
					                    
	
	push rdx
	push rax
	print mssg_quot, mssg_quot_len              
	pop rax			               
	
	mov ebx, eax
	call display64			                
	print newline, 1
	
	print mssg_rem, mssg_rem_len	           
	pop rdx			              
	
	mov ebx, edx			
	call display64			              
	print newline, 1
	print newline, 1
	ret

ascii_hex64:					; procedure start
	mov rbx, 0			; setting rbx to 0
	mov rsi, num1			; rsi point to num1 
	mov rcx, 16			; setting counter resgister to 16
	
	next :				; label to loop
		rol rbx, 4			; shifting rbx to 4bit by left
		mov al, [rsi]		; moving rsi value in al
		
		cmp al, '9'			; comparing al with '9'
		jbe sub30			; if below or equal go to sub30
		sub al, 7h			; sub 7h from al 

		sub30:			
			sub al, 30h	; sub 30h from al
		
		add bl, al			; add al and bl
		inc rsi			; increment rsi to get new digit

		loop next			; if rcx != 0 go to next and decrement rcx
	ret				; return from procedure
 						                
display:					; procedure to display
	mov rsi, temp			; rsi point to temp
	mov rcx, 16			; setting count register to 16
	
	nxt:				; label to loop
		rol rbx, 4			; rotating rbx through 4 bit
		mov al, bl			; moving bl to al
		and al, 0Fh		; removing upper 4 bit
		cmp al, 9			; comparing al with '9'
		jbe add30			; if below or equal go to add30

		add al, 7h			; add 7h to al

		add30 :	
			add al, 30h	; add 30h to al

		mov [rsi], al		; moving al value to rsi
		inc rsi			; increment rsi to go to next digit
		loop nxt			; if rcx != 0 go to next and decrement rcx

	output temp, 16			; print the number
	output endl, 1			; provide space between numbers
	ret				; return from procedure
				                    
						                
ascii_hex32:				; procedure start
	mov rbx, 0			; setting rbx to 0
	mov rsi, num2			; rsi point to num2
	mov rcx, 8				; setting counter resgister to 8
	
	next2:				; label to loop
		rol ebx, 4			; shifting rbx to 4bit by left
		mov al, [rsi]		; moving rsi value in al
		
		cmp al, '9'			; comparing al with '9'
		jbe sub30			; if below or equal go to sub30
		sub al, 7h			; sub 7h from al 

		sub30:			
			sub al, 30h	; sub 30h from al
		
		add bl, al			; add al and bl
		inc rsi			; increment rsi to get new digit

		loop next2		; if rcx != 0 go to next and decrement rcx
	ret				; return from procedure