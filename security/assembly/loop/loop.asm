%include "utils.asm"

global _start

section .text
_start:
	mov rdi, msg
	call printstr
	call readint 
	mov [user_input], rax
	mov rbx, 1

loop:
	mov rcx, [user_input]
	imul rcx, rbx
	mov rdi, rcx
	call printint
	call endl
	add rbx, 1
	cmp rbx, 11
	jne loop
	call exit0

section .data
	msg: db "Enter Number: ", 0

section .bss
	user_input: resb 8