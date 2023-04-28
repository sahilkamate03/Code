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
	write wel_msg, wel_msg_len
	read string, 10
	mov rbx, rax
	write string, rbx

exit:
	mov rax, 60
	mov rdi, 69
	syscall

section .data
	wel_msg: db "Enter String: "
	endl: db 10
	wel_msg_len: equ $-wel_msg

section .bss
	string: resb 10