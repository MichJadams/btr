.386 
.model flat, c
.const 
FibVals		DWORD 0,1,1,2,3,5,8,13,21
			DWORD 34,55,89,144,233,377,610

NumFibVals  DWORD($-FibVals)/sizeof DWORD  ; $ =  same as numfibvals = sizeof(FibVals)/sizeof(int)

			public	NumFibVals

.code 

MemoryAddressing		proc 
				
				push ebp 
				mov ebp, esp 

				push ebx 
				push esi 
				push edi

				xor eax, eax ; check eax for value 
				mov ecx, [ebp+8] ; ecx equals the first param, ecx = i 

				cmp ecx, 0 ; check if i = 0 
				jl invalidIndex ; jump if less than

				;check if i is greater than the length of the array 
				cmp ecx, [NumFibVals]
				jge invalidIndex ; jump if greater or equal to the cmp value above (which sets the flag in the register)

				; example 1  
				mov ebx, OFFSET	FibVals ; ebx becomes fibvals 
				mov esi, [ebp + 8] ; puts i into esi 
				shl esi, 2 ; shift left. mulitplies i by 4 - this 
				add ebx, esi ; add esi to ebx 
				mov eax, [ebx] ; put ebx into the accum register 
				mov edi, [ebp+12]
				mov [edi], eax

				; example 2se base register plus displacment s (esi)
				mov esi, [ebp + 8] 
				shl esi, 2; 
				mov eax, [esi+FibVals]
				mov edi, [ebp+16] ; param v2
				mov [edi], eax

				; eq 3base register plus index register 

				mov ebx, offset FibVals
				mov esi, [ebp + 8] 
				shl esi, 2
				mov eax, [ebx+esi] ; uses base registert ebx plus index register, esi 
				mov edi, [ebp+20] ; param v3 
				mov [edi], eax


				;eq 4 base register plus index rtegister mulitpled by scale factor 
				mov ebx, OFFSET FibVals 
				mov esi, [ebp + 8]
				mov eax, [ebx+esi*4]
				mov edi, [ebp+24]
				mov [edi], eax

				mov eax, 1 ; set return value into eax. Return value is 1 

invalidIndex: 

				pop edi
				pop esi 
				pop ebx 
				pop ebp 

				ret

MemoryAddressing endp 
end 