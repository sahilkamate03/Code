global _start

section .text

_start:
	mov rax, 1
	mov rdi, 1
	mov rsi, nameInput
	mov rdx, nameInput_len
	syscall

user_input:
	mov rax, 0
	mov rdi, 0
	mov rsi, input
	mov rdx, 100
	syscall
	mov rbx, rax

print_greeting:
	mov rax, 1
	mov rdi, 1
	mov rsi, hello
	mov rdx, hello_len
	syscall

print_userInput:
	mov rax, 1
	mov rdi, 1
	mov rsi, input
	mov rdx, rbx
	syscall

exit:
	mov rax, 60
	mov rdi, 69
	syscall

section .data
	nameInput: db 'Enter your name: '
	nameInput_len: equ $-nameInput 
	
	hello: db 'Hello, '
	hello_len: equ $-hello 

section .bss
	input: resb 100
