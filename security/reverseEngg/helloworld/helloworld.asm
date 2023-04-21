global _start

section .text

_start:
	; print hello world
	mov rax, 1 ;write syscall
	mov rdi, 1 ;fd -> 1 (output)
	mov rsi, hello ;buf -> hello ("hello world")
	mov rdx, 11 ;count -> 11 (size)
	syscall

	;exit
	mov rax, 60 ;exit syscall
	mov rdi, 69 ;status code 
	syscall 

section .data
	hello: db 'hello world'
