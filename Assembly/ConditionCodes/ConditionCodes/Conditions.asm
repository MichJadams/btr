.model flat, c 
.code 

signedMinA	proc 

			push ebp 
			mov ebp, esp
			mov eax, [ebp+8] ; a
			mov ecx, [ebp+12] ; b

			cmp eax, ecx 
			jle @F ; jump forward, @b jumps backwards. Jump to nearest @@ symbol if <= 
			mov eax, ecx ; eax = min(a,b). cmp subtracts the source from the destination operand 
			

@@:			mov ecx, [ebp+16]
			cmp eax, ecx
			jle @F
			mov eax, ecx 
@@:			
			pop ebp 
			ret 
signedMinA	endp 

; find max 
signedMaxA	proc 

			push ebp 
			mov ebp, esp
			mov eax, [ebp+8] ; a
			mov ecx, [ebp+12] ; b

			cmp eax, ecx 
			jge @F ; jump if greater than or equal to otherwise move ecx into eax 
			mov eax, ecx ; eax = min(a,b). cmp subtracts the source from the destination operand 
			

@@:			mov ecx, [ebp+16]
			cmp eax, ecx
			jge @F ; jump if greater than. if eax >= ecx 
			mov eax, ecx 
@@:			
			pop ebp 
			ret 
signedMaxA	endp

signedMinB	proc 

			push ebp 
			mov ebp, esp
			mov eax, [ebp+8] ; a
			mov ecx, [ebp+12] ; b

			cmp eax, ecx
			cmovg eax, ecx ; cmov compies its destination into wax if eax is greater than ecx. 
			; for unsigned integers used cmova. 
			mov ecx, [ebp+16]
			cmp eax, ecx
			cmovg eax, ecx ; cmov compies its destination into wax if eax is greater than ecx. 
			
			pop ebp 
			ret 
signedMinB	endp

signedMaxB	proc 

			push ebp 
			mov ebp, esp
			mov eax, [ebp+8] ; a
			mov ecx, [ebp+12] ; b

			cmp eax, ecx
			cmovl eax, ecx ; cmov compies its destination into wax if eax is greater than ecx. 
			; for unsigned integers used cmova. 
			mov ecx, [ebp+16]
			cmp eax, ecx
			cmovl eax, ecx ; cmov compies its destination into wax if eax is greater than ecx. 
			
			pop ebp 
			ret 
signedMaxB	endp
end 


