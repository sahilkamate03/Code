%macro print 2			;Macro for printing 
	mov rax, 1		;rax = 1 for sys_write	
	mov rdi, 1		;unsigned int file descriptor
	mov rsi, %1		;Buffer address
	mov rdx, %2		;Buffer length
	syscall		;Makes system call
%endmacro

%macro input 2			;Macro for reading 
	mov rax, 0		;rax = 0 for sys_read
	mov rdi, 0		;unsigned int file descriptor
	mov rsi, %1		;Buffer address
	mov rdx, %2		;Buffer length
	syscall		;Makes system call
%endmacro

section .data			;For declaring initialized data
	
	mssg db "Write a X86/64 ALP to perform non-overlapped bloack transfer with and without string specific instructions."
	mssg_len:equ $ - mssg					
	mssg_name db "Shivanshu Tiwari"		;Initialising mssg_name 
	mssg_name_len: equ $-mssg_name	
			
	mssg_sel db "--> Select an option from the menu : "
	mssg_sel_len: equ $ - mssg_sel
	mssg_menu db "--> Menu :", 10, "1. Without string specific instruction", 10, "2. With string specific instruction", 10, "3. Exit", 10
	mssg_menu_len: equ $ - mssg_menu
	
	;===================Messages printed during input================================= 
	mssg1 db "Enter your 64-bit Hex number : "			
	mssg1_len: equ $-mssg1		
	
	;===================Messages printed during display of result=====================
	mssg_ss db " == > With String Specific instructions : "
	mssg_ss_len: equ $-mssg_ss
	mssg_wss db " == > Without String Specific instructions : "
	mssg_wss_len: equ $-mssg_wss
	mssg_src db "Printing Source block : "
	mssg_src_len: equ $-mssg_src
	mssg_dest db "Printing Destination block : "
	mssg_dest_len: equ $-mssg_dest
	mssg2 db 10, "    Address     -     Value     ", 10		
	mssg2_len: equ $-mssg2
	mssg_error db "Error!!"				
	mssg_error_len:equ $-mssg_error			
	mssg0 db "Invalid Option!"	
	mssg0_len: equ $-mssg0
	space db " "	
	newline db 10					
	
section .bss			;For declaring variables.
	num1 resb 17		;Reserving 17 Byte.
	src resq 5		;Reserving 5 quad word for src array.
	dest resq 5		;Reserving 5 quad word for dest array.
	temp resb 16		;Reserving 16 Byte.
	choice resb 2	
	
section .text						;Actual code is present.
	global _start					;has to be declared for linker(ld).
	_start: 					;tells linker entry point.
	
	print mssg, mssg_len				;Problem Statement.
	print newline, 1				
	print mssg_name, mssg_name_len		;Name and roll number.
	print newline, 1
	
	;=================Input and counting positive and negative numebers=================
	mov rsi, src 				;Pointing to rsi to first index of src
	mov rcx, 5
	next0 :
		push rcx
		push rdi
		push rsi				;Pushing registers in stack to avoid change in values
		
		print mssg1, mssg1_len
		input num1, 17
		call ascii_hex64
		
		pop rsi
		pop rdi
		mov [rsi], rbx
		;mov [rdi], 0				
		add rsi, 8				;Making rsi point to next element
		add rdi, 8	
		pop rcx
	loop next0
			
	;=================menu to choose from with/without string specific instructions=================
	menu:
		
		print mssg_menu, mssg_menu_len	;Printing menu
		print newline, 1
		print mssg_sel, mssg_sel_len		;Choosing option
		input choice, 2
		
		case_1:
			cmp byte[choice], 31h		
			jne case_2
			call Without_string_specific	;Calling Without_string_specific Procedure when choice is 1
			jmp menu
		case_2:	
			cmp byte[choice], 32h
			jne case_3
			call With_string_specific	;Calling With_string_specific Procedure when choice is 2
			jmp menu
		case_3:
			cmp byte[choice], 33h
			je Exit			;Exiting when choice is 1
			print mssg0, mssg0_len
			print newline, 1
			jmp menu
			
	Exit:
	mov rax, 60					;rax = 60 for sys_exit.
	mov rdi, 0
	syscall
	err:
		print mssg_error, mssg_error_len	;Error mssg for invalid input.
		print newline, 1
		mov rax, 60				
		mov rdi, 0
		syscall
	
	
Without_string_specific:
	print mssg_wss, mssg_wss_len
	print newline, 1
	
	print mssg_src, mssg_src_len			
	mov rsi, src
	call Print_block				;Printing source block
	print newline, 1
	
	print mssg_dest, mssg_dest_len		
	mov rsi, dest
	call Print_block				;Printing destination block
	print newline, 1
	
	mov rcx, 5					;Going through all the elements and transfering
	mov rsi, src					;it from source to destination
	mov rdi, dest					;rsi points to src and rdi to dest
	next1_itr:
		mov rax, [rsi]
		mov [rdi], rax				;Copying from rsi to rdi
		add rsi, 8				;Incrementing rsi and rdi by 8 byte
		add rdi, 8
	loop 	next1_itr
	
	print mssg_src, mssg_src_len
	mov rsi, src
	call Print_block				;Printing source block
	print newline, 1
	
	print mssg_dest, mssg_dest_len
	mov rsi, dest
	call Print_block				;Printing destination block
	print newline, 1
	ret

With_string_specific:
	print mssg_ss, mssg_ss_len
	print newline, 1
	
	print mssg_src, mssg_src_len
	mov rsi, src
	call Print_block				;Printing source block
	print newline, 1
	
	print mssg_dest, mssg_dest_len
	mov rsi, dest
	call Print_block				;Printing destination block
	print newline, 1
	
	mov rsi, src					;rsi points to src+32 and rdi to dest+16
	mov rdi, dest
	cld
	mov rcx, 5
	rep movsq					;This string instruction copying value from src to dest 
							;While inc or dec rdi and rsi based on direction flag
	
	print mssg_src, mssg_src_len
	mov rsi, src
	call Print_block				;Printing source block
	print newline, 1
	
	print mssg_dest, mssg_dest_len
	mov rsi, dest
	call Print_block				;Printing destination block
	print newline, 1
	ret
	
Print_block:
	push rsi
	print mssg2, mssg2_len
	pop rsi
	mov rcx, 5
	next_itr:
		push rcx
		mov rbx, rsi				;Moving address stored in rsi to rbx
		push rsi
		
		print newline, 1
		call display64				;Printing address of current element
		print space, 1				;Giving space
		
		pop rsi
		mov rbx, [rsi]				;Printing value of current element
		push rsi
		
		call display64
		print newline, 1
		
		pop rsi
		add rsi, 8				;Incrementing rsi by 8 byte
		pop rcx
	loop 	next_itr
	ret
	
ascii_hex64:
	mov rcx, 16  					
	mov rsi, num1					;rsi points to num1
	mov rbx, 0 					
	next:						
		rol rbx, 4				;Rotating by 4 bits to left, 0Fh -> F0h
		mov al, [rsi]				;Assigning [rsi] to al
		
		cmp al, 2Fh 				;Checking For Error
		jbe err				;Case: al < 30h (0)
		cmp al, 47h	
		jge err				;Case: al > 46h  (F)
		cmp al, 39h				
		jle ELSE				;Case: al <= 39h (9), No Error
		cmp al, 40h				
		jle err				;Case al > 39(9) and al < 41(A)
		
		ELSE:
							
		cmp al, 39h				;Here we convert ascii to hex
		jbe  sub30h				;If al <= 39h (9), subtract 30h
		sub al, 7h				;Else subtract 37h
		sub30h:
			sub al, 30h			;Subtracting 30h from al
		add bl, al				
		inc rsi				
		dec rcx				
	jnz next
	
	ret 						;Return


display64:
	mov rcx, 16					
	mov rsi, temp					;rsi points to len
	next1:	
		rol rbx, 4				;rotating by 4 bits to left
		mov al, bl				
		and al, 0Fh				;To get only last digit, eg. 5Ah & 0Fh = 0Ah
		cmp al, 9h				;Case : al <= 9h (9)
		jbe add30h				;If True add 30h
		add al, 7h				;Else add 37h

		add30h:
			add al, 30h			;Adding 30h to al
		mov [rsi], al				;Storing al in temp
		inc rsi				
		dec rcx				
	jnz next1
	
	print temp, 16					;Printing number in ascii
	ret						;Return	
