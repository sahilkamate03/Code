;	Name    : Shivanshu Tiwari
;	Roll NO : 7252
;	Write X86/64 ALP to perform multiplication of two 8-bit hexadecimal numbers. Use successive addition and add and shift method. (Use of 64-bit registers is expected).
;	Date    : /04/22

; Macro for write
%macro write 2
	mov rax, 1
	mov rdi, 1
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

; Macro for read
%macro read 2
	mov rax, 0
	mov rdi, 0
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

section .data
	msg db "------------------MENU------------------", 10
	    db "	1. Successive Addition ", 10
	    db "	2. Add and Shift ", 10
	    db "	3. Exit ", 10
	    db "Enter your choice : "
	msglen equ $-msg
	msg1 db "Number : "
	len equ $-msg1
	endl db 10

section .bss
	
	choice resb 2
	num resb 3	
	num1 resb 1
	num2 resb 1
	
	temp resd 1

section .text
	global _start
_start :
	main_menu :
		write msg, msglen
		read choice, 2
		
		
		cmp byte[choice], "1"
		je case1
		
		cmp byte[choice], "2"
		je case2
		
		cmp byte[choice], "3"
		je case3
		
	
	jmp main_menu
	
	case1 :
		write msg1, len
		read num, 3
		call ascii_hex
		mov [num1], bl

		write msg1, len
		read num, 3
		call ascii_hex
		mov [num2], bl
		
		call successive_addition
		jmp main_menu
		
	case2 :
		write msg1, len
		read num, 3
		call ascii_hex
		mov [num1], bl

		write msg1, len
		read num, 3
		call ascii_hex
		mov [num2], bl

		call add_shift
		jmp main_menu
	case3 :
		mov rax, 60
		mov rdi, 0
		syscall

; Procedure to perform Successive Addition to compute multiplication of two numbers
successive_addition:
	mov cl, [num2]
	mov rbx, 0
	mov al, [num1]
	next_add :
		add bx, ax
		loop next_add
	call display
	ret

; Procdure to perform Add and Shift method to compute multiplication of two numbers
add_shift:
	mov rbx, 0
	mov al, [num1]
	mov dl, [num2]
	mov cl, 8
	
	next_shift :
		bt rdx, 0
		jnc ahead
		add bx, ax
		
		ahead :
		rol ax, 1
		ror dl, 1
		loop next_shift
	call display
	ret
		

; Procedure to convert ascii to heaxadecimal number		
ascii_hex:
	mov bl, 0
	mov rsi, num
	mov rcx, 2
	
	next :
		rol bl, 4
		mov al, [rsi]
		cmp al, '9'
		jbe sub30h
		sub al, 7h
		
		sub30h :
			sub al, 30h
		add bl, al
		inc rsi
		loop next
		
		ret
			
; Procedure to convert hexdecimal number to ascii
display :
	mov rsi, temp
	mov rcx, 4
	next1 :
		rol bx, 4
		mov al, bl
		and al, 0Fh
		cmp al, 9
		jbe add30h
		
		add al, 7h
		
		add30h :
			add al, 30h
			mov [rsi], al
			inc rsi
			loop next1
			
			write temp, 4
			write endl, 1
		ret

	
	
	
	
	
	
	
	
	
	
	
	
