global _start

section .text

_start:
	jmp main ; unconditional jump

main:
	mov rax, 0
	mov rdi, 0
	mov rsi, user_key
	mov rdx, 64
	syscall

cmp_key:
	cmp rax, original_key_len
	jne access_denied
	mov rsi, original_key
	mov rdi, user_key
	mov rcx, original_key_len
	repe cmpsb 
	jne access_denied
	je access_granted

access_granted:
	mov rax, 1
	mov rdi, 1
	mov rsi, access_granted_msg
	mov rdx, access_granted_msg_len
	syscall
	jmp exit

access_denied:
	mov rax, 1
	mov rdi, 1
	mov rsi, access_denied_msg
	mov rdx, access_denied_msg_len
	syscall

exit:
	mov rax, 60
	mov rdi, 1
	syscall

section .data
	access_granted_msg: db "Access Granted", 10
	access_granted_msg_len: equ $-access_granted_msg

	access_denied_msg: db "Access Denied", 10
	access_denied_msg_len: equ $-access_denied_msg

	original_key: db "sahil"
	original_key_len: equ $-original_key

section .bss
	user_key: resb 64