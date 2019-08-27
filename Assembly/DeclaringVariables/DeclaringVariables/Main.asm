.386 
.model flat

.data 
num1	dword 11111111h
num2	dword 10101010h
ans		dword 0

.code 
Start	proc 
		mov eax,num1
		add eax,num2
		mov ans, eax
		ret
Start	endp
end		Start