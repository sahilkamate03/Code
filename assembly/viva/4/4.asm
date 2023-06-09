; Assignment Number : 04
; Problem defination : Write an ALP program to count number of positive and negative number entered by user.
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

%macro output 2
	mov rax, 1		; system call for write
	mov rdi, 1		; defining stream i.e stdout
	mov rsi, %1	; rsi point to buffer	
	mov rdx, %2	; rdi stores buffer length
	syscall
%endmacro

section .data                                         		
    	 msg1 db "Enter five Number "                    ;variable msg1 of string data type
     	 msg1len:equ $-msg1                               ;length of msg1

     	 msg2 db "Negative count : "                      ;variable msg2 of string data type
     	 msg2_len:equ $-msg2                               ;length of msg2

      	msg3 db "Positive count : "                       ;variable msg3 of string data type
      	msg3_len:equ $-msg3                              ;length of msg3

	endl db 10			;for new line
       
section .bss                          
	num1 resb 17                 ;variable to store number
     	pc resb 1                        ;variable to store positive count
     	nc resb 1                        ;variable to store negative count
     	temp resb 2                   ;buffer temp of 2 bytes used in display procedure
     
section .text                         
      	global _start                   ;program starts here
      _start:                    
	output msg1, msg1len	;print message 1
	output endl, 1		;new line
       	 mov rcx, 5                   	;intialising 5 to counter register
       	 fl:               
		push rcx            	;pushing rcx into stack
           	input num1, 17           ;taking input in num1
	  	call ascii_hex             ;converting input to hexadecimal 64 bit
	   	bt rbx , 63		;check 63rd Bit of rax
	   	jc nci		;Jump Carry Checks if carry gen is 1 or not
	   	inc byte[pc]	;increase count of pcount by 1 byte
	   	jmp skip		;go to skip
           		nci:
	        		inc byte[nc]	      ;increase count of ncount by 1 byte
           		skip:
				pop rcx		      ;pop rcx from stack
	      		loop fl		      ;Loop goto fl if check rcx != 0 and decrement rcx 
	       
	    
	mov rbx,[nc]                   	;moving value in nc to rbx
	output msg2,msg2_len           	;printing msg2
	call display_8                 	;call to display_8
	
	mov rbx,[pc]                  	 ;moving value in pc to rbx
	output msg3,msg3_len           	 ;printing msg3
	call display_8                 	;call to display_8
	
	
        	mov rax,60                     	;sys call for exit
       	mov rdi,0
        	syscall

ascii_hex:					; procedure start
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

display_8:					; procedure to display
	mov rsi, temp			; rsi point to temp
	mov rcx, 2				; setting count register to 2
	
	nxt:				; label to loop
		rol bl, 4			; rotating rbx through 4 bit
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

	output temp, 2			; print the number
	output endl, 1			; provide space between numbers

	ret				; return from procedure
