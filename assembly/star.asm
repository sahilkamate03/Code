section .text
	global _start

_start:	
	mov edx,len ;data register
	mov ecx,msg ;count register
	mov ebx,1 ;index register (stdout)
	mov eax,4 ;sys_write
	int 0x80

	mov edx,9
	mov ecx,s2
	mov ebx,1
	mov eax,4
	int 0x80

	mov eax,1
	int 0x80

section .data
	msg db '5 star',0xa
	len equ $ - msg 
	s2 times 9 db '*'


;ecx stores the pointer