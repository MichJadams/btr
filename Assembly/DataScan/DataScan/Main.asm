.386

.model flat 

.data 
;intArray SWORD 0,0,0,0

intArray SWORD 0,0,0,0,4,18,50 ; example of an array with some non zero values 
.code 
start	proc 
		 mov ebx, OFFSET intArray
		 mov ecx, LENGTHOF intArray

L1:		
		cmp WORD PTR[ebx], 0
		jnz		found 
		add		ebx,2
		loop	L1
		jmp		notFound

found: 
		movsx eax, WORD PTR[ebx]
		jmp quit 

notFound:	
		mov eax, 999999 ; this value gets put in eax if no non zero values were found

quit:
	ret 

start endp 
end start 