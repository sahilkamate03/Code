section .data
	userMsg db 'Please enter a number: '
	lenUserMsg equ $ - userMsg
	displayMsg db 'You have entered: '
	lenDisplayMsg equ $ - displayMsg

section .bss
	num resb 5

section .text
	global _start

_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, userMsg
	mov edx, lenUserMsg
	int 80h

	mov eax, 3
	mov ebx, 2
	mov ecx, num
	mov edx, 5
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, displayMsg
	mov edx, lenDisplayMsg
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, num
	mov edx, 5
	int 80h

	mov eax, 1
	mov ebx, 0
	int 80h