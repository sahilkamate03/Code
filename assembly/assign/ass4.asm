;write an asembly level program to display no. of +ve and -ve hexadecimal no. from array
;name : Harshal Patil

%macro write 2				;2 specifies no. of parameters
	mov rax,1
	mov rdi,1
	mov rsi,%1				; %1 specifies 1st parameter
	mov rdx,%2
	syscall;write an asembly level program to store 64 bit 5 hexa deciaml numbers from user and store it in array and display back
;name : Harshal Patil
%endmacro

section .data
	hexnum dq 0F234567890ABCDEFh,0FF23456789ABCDEFh,0ABCDEF1234567890h,0ABCDEF0123456789h,901234567ABCDEF8h,4567890123FEDCBAh
	
	msg db "Numbers are :",10
	msglen equ $-msg
	
	msg1 db "Number of positive numbers are :"
	msg1len equ $-msg1
	
	msg2 db "Number of negative numbers are :"
	msg2len equ $-msg2
	
	msgl db " --------------Problem Statement-----------------",10
	 db "write an asembly level program to display no. of +ve and -ve hexadecimal no. from array ",10
	db "name : Harshal Patil",10
	msgllen equ $-msgl
	
	
	pcount db 0
	ncount db 0
	endl db 10
	
section .bss
	temp resb 16
	temp1 resb 2
	
section	.text
   global _start   
	
_start:  
	write msgl,msgllen
	write endl,1
	
	write msg,msglen
	
	mov rsi,hexnum
	mov rcx,6
	
	next_num:
		mov rbx,[rsi]
		push rsi
		push rcx
		
		call display_64
		
		bt rbx,63
		jnc positive
		
		inc byte[ncount]
		jmp skip
		
	positive:
		inc byte[pcount]
		
	skip:
		pop rcx
		pop rsi
		add rsi,8
		loop next_num
	
	write msg1,msg1len
	mov bl,[pcount]
	call display_8
	
	write msg2,msg2len
	mov bl,[ncount]
	call display_8
	
	mov rax,60
	mov rdi,0
	syscall
	
display_8:
	mov rsi , temp1
	mov rcx , 2
	
	next_digit :
		rol bl, 4
		mov al, bl
		and al,0FH
		cmp al,9
		jbe add30h
		add al,7
		
	add30h :
		add al,30h
		mov [rsi], al
		inc rsi
		
		loop next_digit
		
		write temp1, 2
		write endl, 1
	ret	

	
display_64 :
	mov rsi , temp
	mov rcx , 16
	
	nextdigit :
		rol rbx, 4
		mov al, bl
		and al,0FH
		cmp al,9
		jbe add_30h
		add al,7
		
	add_30h :
		add al,30h
		mov [rsi], al
		inc rsi
		
		loop nextdigit
		
		write temp, 16
		write endl, 1
		
	ret	
