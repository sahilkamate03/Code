; Assignment Number : 01
; Problem defination : Write an ALP program to cin 64 bit hexadecimal number, store in array and display it to user
; Name : Shivanshu Tiwari
; Roll Number : 7252
; Date : 22/03/2022

%macro cin 2
	mov rax, 0		; System call for read
	mov rdi, 0		; defining stream i.e stdin
	mov rsi, %1	; rsi point to buffer	
	mov rdx, %2	; rdi stores buffer length
	syscall
%endmacro

%macro cout 2
	mov rax, 1		; system call for write
	mov rdi, 1		; defining stream i.e stdout
	mov rsi, %1	; rsi point to buffer	
	mov rdx, %2	; rdi stores buffer length
	syscall
%endmacro

section .data
	msg1 db "Enter the five Numbers : "             ; store message in msg1
	msg1len equ $-msg1		   ; store message len in meg1len

	endl db 10			

	msg2 db "The Number you Entered are :"		; store message in msg2					
	msg2len equ $-msg2			; store message len in meg2len

section .bss
	hexnum_arr resq 5			; reserve five 64bit in hexnum_arr
	hexnum resb 17			; reserve 17byte for hexnum
	temp resb 16			; reserve 16 byte for temp

section .text
	global _start
      _start:					; indicating start 

	cout msg1, msg1len		; printing message 1 using macro
    cout endl,1

	mov rsi, hexnum_arr		; rsi points to hexnum_arr
	mov rcx, 5				; set count register to 5

	nextnum:				; label to loop
		push rcx			; push rcx to stack
		push rsi			; push rsi to stack

		cin hexnum, 17		; take cin from user and store in hexhum
		call ascii_hex		; convert hexnum from ascii to hex using procedure
		
		pop rsi			; pop rsi from stack
		pop rcx			; pop rcx from stack
		
		mov [rsi], rbx		; storing value of rbx received from procedure in rsi
		add rsi, 8			; adding 64 bit to rsi to point it to next number

		loop nextnum		; if rcx != 0 go to nextnum and decrement rcx

	cout msg2, msg2len		; print message 2 using macro
	cout endl, 1			; print new line

	mov rsi, hexnum_arr			; pointing rsi to hextnum_arr
	mov rcx, 5				; setting counter register to 5

	nextdisp:				; label to loop
		push rcx			; push rcx to stack
		push rsi			; push rsi to stack

		mov rbx, [rsi]		; moving value of rsi to rbx
		call display		; call to procedure to diaplay number

		pop rsi			; pop rsi from stack
		pop rcx			; pop rcx from stack

		add rsi, 8			; adding 64 bit to rsi to point to next number
 
		loop nextdisp		; if rcx != 0 go to nextdisp and decrement rcx

	mov rax, 60			; system call to exit
	mov rsi, 0
	syscall


ascii_hex:					; procedure start
	mov rbx, 0			; setting rbx to 0
	mov rsi, hexnum			; rsi point to hexnum 
	mov rcx, 16			; setting counter resgister to 16
	
	next :				; label to loop
		rol rbx, 4			; shifting rbx to 4bit by left
		mov al, [rsi]		; moving rsi value in al
		
		cmp al, '9'			; comparing al with '9'
		jbe sub30			; if below or equal go to sub30
		sub al, 7h			; sub 7h from al 

		sub30:			
			sub al, 30h	; sub 30h from al
		
		add bl, al			; add al and bl
		inc rsi			; increment rsi to get new digit

		loop next			; if rcx != 0 go to next and decrement rcx
	ret				; return from procedure


display:					; procedure to display
	mov rsi, temp			; rsi point to temp
	mov rcx, 16			; setting count register to 16
	
	nxt:				; label to loop
		rol rbx, 4			; rotating rbx through 4 bit
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

	cout temp, 16			; print the number
	cout endl, 1			; provide space between numbers

	ret				; return from procedure

		