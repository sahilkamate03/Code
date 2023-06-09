; Assignment Number : 02
; Problem defination : Write an X86/64 ALP to accept a string and to display its length
; Name : Shivanshu Tiwari
; Roll Number : 7252
; Date : 05/04/2022

%macro input 2
	mov rax, 0		; system call for read
	mov rdi, 0		; defining stream i.e stdin
	mov rsi, %1	; rsi point to buffer	
	mov rdx, %2	; rdi stores buffer length
	syscall
%endmacro

%macro output 2
	mov rax, 1		; syscall call for write
	mov rdi, 1		; defining stream i.e stdout
	mov rsi, %1	; rsi point to buffer	
	mov rdx, %2	; rdi stores buffer length
	syscall
%endmacro

section .data
	msg1 db "Enter the String : "            			; store message in msg1
	msg1len equ $-msg1				; store message len in meg1len

	endl db 10					; for spaces

	msg2 db "The length of string you Entered is :"		;store message in msg2					
	msg2len equ $-msg2				;store message len in meg2len


section .bss
	string resb 30			; string variable created to store string
	temp resb 2			; defing variable to use in display procedure

section .text
	global _start
_start:					; indicating start 

	output msg1, msg1len		; printing message 1 using macro
	output endl, 1			; print new line

	input string, 30			; input string
	dec rax				; decrement rax as for enter
	mov rbx, rax			; moving length of string to rbx
	call display			; call display to print length	
	
    mov rax, 60			; system call to exit
	mov rsi, 0
	syscall


display:					; procedure to display
	mov rsi, temp			; rsi point to temp
	mov rcx, 2				; setting count register to 2
	
	nxt:				; label to loop
		rol bl, 4			; rotating rbx through 4 bit
		mov al, bl			; moving bl to al
		and al, 0Fh		; removing upper 4 bit
		cmp al, 9			; comparing al with '9'
		jbe add30			; if below or equal go to add30

		add al, 7h			; add 7h to al

		add30 :	
			add al, 30h	; add 30h to al

		mov [rsi], al		; moving al value to rsi
		inc rsi			; increment rsi to go to next digit
		loop nxt			; if rcx != 0 go to next and decrement rcx

	output temp, 2			; print the number
	output endl, 1			; provide new line
	ret				; return from procedure

		