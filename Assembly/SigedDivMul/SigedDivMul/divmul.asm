.386 

.model flat, c

.code
; return : 0 Error division by zero 
; return 1: implied sucess

; computation : *prod = a* b
; quo = a/b 
; rem = a%b

IntegerMulDiv	proc 
			push ebp ; save the old values of ebp
			mov ebp, esp ; ebp now points to the top of the stack
			push ebx ; preserve the non volitile registers 

			xor eax, eax ; check that divisor is not equal to zero 
			mov ecx, [ebp + 8] ; ecx = a ; ebx is the base pointer register 
			mov edx, [ebp + 12] ; edx = b 

			or edx, edx ; doing a bitwise or compairson with itself while preserving the original value 
			; again, this is just checking for division by zero 
			jz invalidDivisor ; conditional jump instruction, jump if zero 
			; if b != zero 

			imul edx, ecx ; multiplies ecx(which is a) by edx( which is b) and stores it in edx 
			mov ebx, [ebp + 16] ; ebx = prod
			mov [ebx], edx 

			mov eax, ecx ; eax = ecx which is equal to a 
			cdq ; compare quad word. extends the contens of reg eax. 
			idiv dword ptr[ebp + 12] ; preformed the signed integer division. The content of eax and ecx are always used as the 
			; dividend 

			mov ebx, [ebp + 20]
			mov [ebx], eax ; saves the quotient 
			mov eax, [ebp + 24]
			mov [ebx], edx ; save the remainder 
			mov eax, 1 

invalidDivisor:

			pop ebx ; these registers must be restored. If an assembly function failes to restore a 
			; non volitile register (which it changed). A crash might occure. 
			pop ebp 
			ret 0 

IntegerMulDiv endp 
end 