section .data
    hello db 'Hello, world!',0 ; null-terminated string

section .text
    global _start

_start:
    ; write the string to stdout
    mov rax, 1      ; syscall number for write
    mov rdi, 1      ; file descriptor for stdout
    mov rsi, hello  ; address of the string
    mov rdx, 13     ; length of the string
    syscall

    ; exit with status 0
    mov rax, 60     ; syscall number for exit
    xor rdi, rdi    ; exit status (0)
    syscall



