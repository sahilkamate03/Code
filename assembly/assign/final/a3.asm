;Sahil Kamate 7246
;Write a switch case driven X86/64 ALP to perform 64-bit hexadecimal arithmetic operations (+, -, *, /) using suitable macros. Define procedure for each operation.

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
	write endl, 1

exit:
	mov rax, 60
	mov rdi, 69
	syscall

section .data
	wel_msg: db "Write a switch case driven X86/64 ALP to perform 64-bit hexadecimal arithmetic operations (+, -, *, /) using suitable macros. Define procedure for each operation."
	wel_msg_len: equ $-wel_msg

	endl: db 10
section .bss
