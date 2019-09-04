.model flat, c

.code 
calculateArraySum	proc 

					push ebp
					mov ebp, esp
					
					mov edx, [ebp+8]
					mov ecx, [ebp+12]

					xor eax, eax ; eax = sum 

					;check if the array length is greater than 0
					cmp ecx, 0 
					jle invalidCount
@@:
					add eax, [edx] ; add next element in the sum, using the counter register to point to it 
					add edx, 4 ; set pointer to next element 
					dec ecx ; decrement the counter 
					jnz @b ; jump backwards to the next @ lable if ecx is not equal to zero  

					
invalidCount:
					pop ebp
					ret 
calculateArraySum endp 
end 