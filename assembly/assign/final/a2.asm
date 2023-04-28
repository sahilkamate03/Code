;Sahil Kamate 7246
;Write an X86/64 ALP to accept a string and to display its length.

%macro read 2
	mov rax, 0           ; Set system call number to 0 (sys_read)
	mov rdi, 0           ; Set file descriptor to 0 (stdin)
	mov rsi, %1          ; Set buffer address to the first argument
	mov rdx, %2          ; Set buffer size to the second argument
	syscall               ; Invoke the system call
%endmacro

%macro write 2
	mov rax, 1           ; Set system call number to 1 (sys_write)
	mov rdi, 1           ; Set file descriptor to 1 (stdout)
	mov rsi, %1          ; Set buffer address to the first argument
	mov rdx, %2          ; Set buffer size to the second argument
	syscall               ; Invoke the system call
%endmacro

section .text

GLOBAL _start
_start:
	write wel_msg, wel_msg_len
	write endl, 1

	write user_input_msg, user_input_msg_len ; Display "Enter String: " message
	read user_input, 100                     ; Read input from user into user_input buffer
	mov rbx, rax                            ; Store the length of user input in rbx
	write length_msg, length_msg_len         ; Display "Length: " message
	call display                           ; Call display subroutine to process input

exit:
	mov rax, 60          ; Set system call number to 60 (sys_exit)
	mov rdi, 69          ; Set exit status to 69
	syscall               ; Invoke the system call to exit the program

display:
	mov rsi, temp        ; Set rsi to point to the temp buffer
	mov rcx, 2           ; Set loop counter rcx to 2

	nxt:
		rol bl,4          ; Rotate the 4 least significant bits of rbx to the left
		mov al, bl        ; Move the rotated bits to al
		and al, 0Fh       ; Mask the upper bits of al to get only the lowest 4 bits
		cmp al, 9         ; Compare al with 9
		jbe add30         ; Jump if al is less than or equal to 9 to add30 label

		add al, 7h        ; Add 7 to al to convert it to ASCII representation of A-F

		add30:
			add al, 30h   ; Add 30h to al to convert it to ASCII representation of 0-9

		mov [rsi], al     ; Store the ASCII value in the temp buffer
		inc rsi           ; Increment rsi to point to the next byte in the buffer
		loop nxt          ; Repeat the loop until rcx becomes 0

	write temp, 2        ; Display the processed input in temp buffer
	write endl, 1        ; Display a newline character
	ret                  ; Return from the subroutine

section .data
	wel_msg: db "Write an X86/64 ALP to accept a string and to display its length."
	wel_msg_len: equ $-wel_msg

	user_input_msg: db "Enter String: "
	user_input_msg_len: equ $-user_input_msg

	length_msg: db "Length: "
	length_msg_len: equ $-length_msg

	endl: db 10

section .bss
	user_input: resb 100 ; Reserve 100 bytes of uninitialized memory for user input
	temp resb 2           ; Reserve 2 bytes of uninitialized memory for processed input
