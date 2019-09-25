.386 
.model flat 

.data 
intArray DWORD 10000h, 20000h, 30000h, 40000h;

.code 
Start	proc
		mov edi, OFFSET intArray
		mov ecx, LENGTHOF intArray
		mov eax, 0
LP: 
	add BYTE PTR myArray[ecx], [edi]
	add ecx, TYPE intArray
	loop LP 
	ret 
Start endp
end Start