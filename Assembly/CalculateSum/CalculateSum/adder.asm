.386 
.model flat, c

.code
AdderAsm	proc

		push ebp
		mov ebp, esp
		mov esp, ebp ; esp is current stack pointer register 

		mov eax, [ebp + 8]; eax = a 
		mov ecx, [ebp + 12]; eax = b 
		mov edx, [ebp + 16]; eax = c 

		add eax, ecx ; eax = a + b 
		add eax, edx  ; eax = a + b + c

		pop ebp ; pop the value in ebp 

		ret  ; transfers program control abck to the c function 

AdderAsm ENDP 
END