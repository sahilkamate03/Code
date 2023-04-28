;hi
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
			

exit:
	mov rax, 60
	mov rdi, 69
	syscall

section .data

section .bss
