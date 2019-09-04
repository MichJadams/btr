.model flat, c 

.code 

squarArrayAsm		proc 
					push ebp 
					mov ebp, esp 

					push ebx
					push esi 
					push edi 

					;load arguments 
					mov edi, [ebp +8]
					mov esi, [ebp +12]
					mov ecx, [ebp + 16]


					xor eax, eax ; eax = sum of y array

					cmp ecx, 0  ; ecx has the array length 
					jle invalidLength

					shl ecx, 2 ; logical shift left, mul by 2 to the x, where x = 2. ecx is not the size of the aray in bites 
					xor ebx, ebx 


@@:
					mov edx, [esi + ebx] ; load next x[i]
					imul edx, edx ; computes the square of the edx register 
					mov [edi + ebx], edx ; save the term into 'y'
					add eax, edx ; updates the runninng sum 
					add ebx, 4 ; update the array element offset 

					;compare and jump if not finished 
					cmp ebx, ecx 
					jl @B 

invalidLength: 
					pop ebp 
					pop ebx
					pop esi 
					pop edi

					ret 

squarArrayAsm		endp
end 