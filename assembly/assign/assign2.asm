global _start

section .text

_start:
	mov rax, 1
	mov rdi, 1
	mov rsi, input_msg
	mov rdx, input_msg_len
	syscall

	mov rax, 0
	mov rdi, 0
	mov rsi, user_input
	mov rdx, 100
	syscall
	mov rbx, rax 

	mov rax, 1
	mov rdi, 1
	mov rsi, last_msg
	mov rdx, last_msg_len
	syscall

	mov rax, 1
	mov rdi, 1
	mov rsi, rbx
	mov rdx, rbx
	syscall

exit:
	mov rax, 60
	mov rdi, 1
	syscall

section .bss
	user_input: resb 100
	user_input_len: resb 100

section .data
	input_msg: db "Enter msg: "
	input_msg_len: equ $-input_msg

	last_msg: db "Length: "
	last_msg_len: equ $-last_msg