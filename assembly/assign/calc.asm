%macro write 2
	mov rax, 1
	mov rdi, 1
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

%macro read 2
	mov rax, 0
	mov rdi, 0
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

section .data
	msg db "------------------MENU------------------", 10
	    db "	1. Addition ", 10
	    db "	2. Subtraction ", 10
	    db "	3. Division ", 10
	    db "	4. Multiplication ", 10
	    db "	5. Exit ", 10
	    db "Enter your choice : "
	msglen equ $-msg
	msg1 db "Number : "
	len equ $-msg1
	endl db 10
	
section .bss
	choice resb 2
	num resb 17
	
	num1 resq 1
	num2 resq 1
	
	temp resb 16
	
section .text
	global _start:
_start:
	main_menu :
		write msg, msglen
		read choice, 2
		
		cmp byte[choice], "1"
		je case1
		
		cmp byte[choice], "2"
		je case2
		
		cmp byte[choice], "3"
		je case3
		
		cmp byte[choice], "4"
		je case4
		
		cmp byte[choice], "5"
		je case5
	jmp main_menu
	
	
	case1 :
		call addition
		jmp main_menu
	case2 :
		call subtraction
		jmp main_menu
		
	case3 :
		call division
		jmp main_menu
	case4 :
		call multiplication
		jmp main_menu
	case5 :	
		mov rax, 60
		mov rdi, 0
		syscall	

addition :
	write msg1, len
	read num, 17
	
	call ascii_hex
	mov [num1], rbx
	;call display
		
	write msg1, len
	read num, 17
		
	call ascii_hex
	mov [num2], rbx
		
	mov rax, [num1]
	mov rbx, [num2]
		
	add rbx, rax
		
	call display
	ret
subtraction :
	write msg1, len
	read num, 17
	
	call ascii_hex
	mov [num1], rbx
	;call display
		
	write msg1, len
	read num, 17
		
	call ascii_hex
	mov [num2], rbx
		
	mov rax, [num1]
	mov rbx, [num2]
		
	sub rax, rbx
	mov rbx, rax
		
	call display
	ret
	
multiplication :
	write msg1, len
	read num, 17
	
	call ascii_hex
	mov [num1], rbx
	;call display
		
	write msg1, len
	read num, 17
		
	call ascii_hex
	mov [num2], rbx
		
	mov rax, [num1]
	mov rbx, [num2]
		
	mul rbx
	mov rbx, rax
		
	call display
	ret
	
division :
	write msg1, len
	read num, 17
	
	call ascii_hex
	mov [num1], rbx
	;call display
		
	write msg1, len
	read num, 17
		
	call ascii_hex
	mov [num2], rbx
	
	mov edx, 0
	mov eax, [num1]
	mov ecx, [num2]
		
	div ecx
	mov rbx, 0
	mov ebx, eax
		
	call display
	ret
ascii_hex:
	mov rbx, 0
	mov rsi, num
	mov rcx, 16
	
	next :
		rol rbx, 4
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
			

display :
	mov rsi, temp
	mov rcx, 16
	next1 :
		rol rbx, 4
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
			
			write temp, 16
			write endl, 1
	ret
		