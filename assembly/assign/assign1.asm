
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
	msg1 db "Number : "
	msg1len equ $-msg1
	endl db 10

section .bss
	hexnum resq 5
	num1 resb 17
	temp resb 16
	
section .text
	global _start
_start :
	mov rcx, 5
	mov rsi, hexnum
	nextnum :
		push rcx
		push rsi
		write msg1, msg1len
		read num1, 17
		
		call ascii_hex
		pop rsi
		pop rcx
		mov [rsi], rbx
		
		
		add rsi, 8
		loop nextnum
		
	mov rsi, hexnum
	mov rcx, 5
	
	next2:
		push rcx
		push rsi
		
		mov rbx, [rsi]
		call display
		pop rsi
		pop rcx
		add rsi, 8
		loop next2
		
	mov rax, 60
	mov rsi, 0
	syscall
	
ascii_hex:
	mov rbx, 0
	mov rsi, num1
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
	
	
	
	