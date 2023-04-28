%include "../utils.asm"

GLOBAL _start

section .text
_start:

first_input:
	mov rdi, first_digit_input
	call printstr
	call readint
	mov [first_digit_input], rax
	; mov rdi, [first_digit_input]
	; call printint
	; call endl

second_input:
	mov rdi, second_digit_input
	call printstr
	call readint
	mov [second_digit_input], rax
	; mov rdi, [second_digit_input]
	; call printint
	; call endl

operations:
	mov rdi, operation
	call printstr

	mov rax, 0
	mov rdi, 0
	mov rsi, operation_selected
	mov rdx, 2
	syscall

	; mov rdi, operation_selected
	; call printstr
	; call endl

	mov rdi, result_str
	call printstr

	mov rsi, add_sign
	mov rdi, operation_selected
	mov rcx, 1
	repe cmpsb
	je addition

	mov rsi, sub_sign
	mov rdi, operation_selected
	mov rcx, 1
	cmpsb
	je subtraction

	mov rsi, mul_sign
	mov rdi, operation_selected
	mov rcx, 1
	repe cmpsb
	je multiplication

	mov rsi, div_sign
	mov rdi, operation_selected
	mov rcx, 1
	repe cmpsb
	je division

	jmp exiting

addition:
	mov rax, [first_digit_input]
	add rax, [second_digit_input]
	mov rdi, rax
	call printint
	jmp exiting

subtraction:
	mov rax, [first_digit_input]
	sub rax, [second_digit_input]
	mov rdi, rax
	call printint
	jmp exiting

multiplication:
	mov rax, [first_digit_input]
	imul rax, [second_digit_input]
	mov rdi, rax
	call printint
	jmp exiting

division:
	mov rdx, 0
	mov rax, [first_digit_input]
	mov rbx, [second_digit_input]
	idiv rbx
	mov rdi, rbx
	call printint
	jmp exiting

exiting:
	call endl
	call exit0

section .data
	first_digit_input: db "Enter the first number: ", 0
	second_digit_input: db "Enter the second number: ", 0
	operation: db "Operation (+, -, *, /): ", 0
	result_str: db "Result: ", 0

	add_sign: db "+", 0
	sub_sign: db "-", 0
	mul_sign: db "*", 0
	div_sign: db "/", 0

section .bss
	operation_selected: resb 10