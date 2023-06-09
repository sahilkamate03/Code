; Problem defination : Write X86/64 ALP to convert 4-digit Hex number into its equivalent BCD number and 5-digit BCD number into its equivalent HEX number
; Name : Sahil Kamate


%macro input 2
	mov rax, 0		; System call for read
	mov rdi, 0		; defining stream i.e stdin
	mov rsi, %1	; rsi point to buffer	
	mov rdx,%2	; rdi stores buffer length
	syscall
%endmacro

%macro print 2
	mov rax, 1		; system call for write
	mov rdi, 1		; defining stream i.e stdout
	mov rsi, %1	; rsi point to buffer	
	mov rdx,%2	; rdi stores buffer length
	syscall
%endmacro

section .data                         
     	 msg1 db "Enter 4-digit Hex number: "            	;variable msg1 of string data type
     	 msg1_len:equ $-msg1                              		;length of msg1


     	 msg2 db "Enter 5-digit BCD number: "             	;variable msg2 of string data type
     	 msg2_len:equ $-msg2                              		;length of msg2

     	 msg3 db "Equivalent HEX is: "                    	;variable msg3 of string data type
      	 msg3_len:equ $-msg3                              		;length of msg3

      	msg4 db "Equivalent BCD is: "                    	;variable msg4 of string data type
      	msg4_len:equ $-msg4                              		;length of msg4

      	menu db "1 HEX-BCD",10, "2 BCD-HEX",10,"3 EXIT",10	;menu for user
      	menu_len:equ $-menu

      	newLine db 10                                    		;for newline
       
section .bss                    
     	bcd resb 6                    	;array bcd of 6 bytes
	hex resb 5                    	;array hex of 5 word
	choice resb 2                 	;array choice of 4 bytes
	temp resb 4                   	;buffer temp of 4 bytes
     
section .text                         
      	global _start                   ;program starts here
      _start:                    
        	while_1:                      			;loop for menu
		print menu,menu_len        		;printing menu message
	   	input choice,2             		;taking input from user as choice
	    
	   	case_1:                     
	   		cmp byte[choice],'1'       	;comparing choice with 31h or '1'
	   		jne case_2                 	;if not equal jump to case2
	   		call hex_bcd               	;call for add_p procedure
	   		jmp while_1                	;jump to label while_1
	   
	   	case_2:
	   		cmp byte[choice],'2'       	;comparing choice with 32h or '2'
	   		jne case_3                 	;if not equal jump to case3
	   		call bcd_hex               	;call for sub_p procedure
	   		jmp while_1                	;jump to label while_1
	    
	   	case_3:
	   		cmp byte[choice],'3'       	;comparing choice with 33h or '3'
	  		 jne while_1                	;if not equal jump to case4

           	mov rax,60                ;sys call for exit
           	mov rdi,0
           	syscall

ascii_hex:					; procedure start
	mov rbx, 0			; setting rbx to 0
	mov rsi, hex			; rsi point to hex 
	mov rcx, 4				; setting counter resgister to 4
	
	next :				; label to loop
		rol bx, 4			; shifting rbx to 4bit by left
		mov al, [rsi]		; moving rsi value in al
		
		cmp al, '9'			; comparing al with '9'
		jbe sub30			; if below or equal go to sub30
		sub al, 7h			; sub 7h from al 

		sub30:			
			sub al, 30h	; sub 30h from al
		
		add bl, al			; add al and bl
		inc rsi			; increment rsi to get new digit

		loop next			; if rcx != 0 go to next and decrement rcx
	ret
              
display:					; procedure to display
	mov rsi, temp			; rsi point to temp
	mov rcx, 4				; setting count register to 4
	
	nxt:				; label to loop
		rol bx, 4			; rotating bx through 4 bit
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

	print temp, 4			; print the number
	print newLine, 1			; provide space between numbers

	ret				; return from procedure
              
hex_bcd:                              			;convert hex to bcd
                	print msg1,msg1_len   		;printing msg1
	input hex,5           			;taking hex input 
	call ascii_hex        			;call to ascii to hex 
		
	mov ax,bx             			;moving bx into ax
   	mov bx,0AH            			;storing 10 in bx
   	mov rcx,5             			;moving 5 into rcx
   	mov rdi,bcd+4         			;pointing rdi to last element of bcd buffer
	 
	loop1:                      
	        mov rdx,0             		;clearing rdx before div
	        div rbx               			;dividing rax by rbx
	        add dl,30h            		;value in dl has remainder and adding 30h to it to convert to ascii from hex
	        mov [rdi],dl          		;storing dl into rdi
	        dec rdi               			;pointing rdi to its predecessor
	        loop loop1                		;go to loop1 if rcx not 0 and decrement rcx by 1
	       
	print msg4,msg4_len   		;printing msg4
	print bcd,5           			;printing bcd result of given hex
	print newLine,1       			;printing newline
	ret
		
bcd_hex:
 	print msg2,msg2_len   		;printing msg2 
 	input bcd,6           			;taking 6 digit bcd input
 	mov rcx,5             			;moving 5 into rcx
 	mov rdi,bcd           			;pointing rdi to first element of bcd buffer
 	mov ax,0              			;moving 0 into ax
 	mov bx,10             			;moving 10 into bx
 		
	loop2:			
 		mul bx                		;multiplying bx with ax
 		mov dx,0              		;moving 0 into dx
 		mov dl,[rdi]          		;storing dl into rdi
 		sub dl,30h            		;subtract 30h from dl
 		add ax,dx            		;add ax and bx
 		inc rdi               		;pointing rdi to its successor
 		loop loop2		;go to loop2 if rcx not 0 and decrement rcx by 1
 	
 	mov bx,ax              			;moving ax into bx 
 	print msg3,msg3_len    		;printing msg3
 	call display           			;call to display to output result
 	ret				
        
