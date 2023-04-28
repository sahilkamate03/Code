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
  ; ; Display input prompt
  ; mov rax, 1 ; System call for write
  ; mov rdi, 1 ; File descriptor for stdout
  ; lea rsi, [input_prompt] ;Address of input prompt string
  ; mov rdx, 23 ; Length of input prompt string
  ; syscall ; Call the kernel

GLOBAL _start
_start:
  write input_prompt, input_prompt_len

  mov rsi, array ; Address of the array
  mov rcx, array_size ;

input_loop:
  mov rax, 0 ; System call for read
  mov rdi, 0 ; File descriptor for stdin
  lea rsi, [rsi] ; Address of the current element in the array
  mov rdx, 1 ; Number of bytes to read
  syscall ; Call the kernel

  ; Store the input value in the array
  mov [rsi], al ; Store the input byte in the array
  inc rsi ; Move to the next element in the array
  loop input_loop ; Loop until all elements are read

exit:
	mov rax, 60
	mov rdi, 69
	syscall

section .data
	array_size equ 5
	array db array_size dup(0) ; Declare an array of bytes with size 5 and initialize with 0

	input_prompt: db "Enter values for the array: ", 0
	input_prompt_len: equ $-input_prompt

section .bss
