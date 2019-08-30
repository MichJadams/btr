;An assembly program that takes an array and a number and adds all the elements 
; in the array that number of times 
.386
.model flat 

.data 
intArray DWORD 5,4,3 ; the array to add 
multiplier DWORD 2  ; add everything 5 times

.code 
main	proc 

		mov EDI, OFFSET intArray
		mov ECX, LENGTHOF intArray
		mov ESI, multiplier
		mov EAX, 0 

L1: 
		add eax, [edi]
		add edi, TYPE intArray
		loop L1

		mov EDI, OFFSET intArray
		mov ECX, LENGTHOF intArray
		sub ESI, 1 
		CMP ESI, 0
		JNE L1

		ret
main ENDP 
END main 