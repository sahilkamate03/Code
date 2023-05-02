;hello
%macro read 2
	mov rax, 0
	mov rdi, 0
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

%macro write 2
	mov rax, 1
	mov rdi, 1
	mov rsi, %1
	mov rdx, %2
	syscall
%endmacro

section .text

GLOBAL _start
_start:

; 	read choice, 2
; 	mov rbx, rax
; 	write choice, rbx
; 	cmp byte[choice], 31h
; 	je hello_label
; 	mov rax, 60
; 	mov rdi, 69
; 	syscall

; hello_label:
; 	write hello, hello_len
	read user_input, 17
	call ascii_hex64
	mov [hex1], rbx

	read user_input, 17
	call ascii_hex64
	mov [hex2], rbx

	; write [hex2], 16

exit:
	mov rax, 60
	mov rdi, 69
	syscall

ascii_hex64:					; procedure start
	mov rbx, 0			; setting rbx to 0
	mov rsi, user_input		; rsi point to num1 
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
	ret	

section .data
	hello: db "Hello", 10
	hello_len: equ $-hello

section .bss
	choice resb 2
	user_input resb 17

	hex1 resq 1
	hex2 resq 1

	result resq 1

