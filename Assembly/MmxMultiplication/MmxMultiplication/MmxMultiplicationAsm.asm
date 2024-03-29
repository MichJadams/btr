.model flat, c 
.code 
MmxMultiply		proc 
				push ebp
				mov ebp, esp 

				movq mm0, [ebp+8]		; mm0 =  'a' 
				movq mm1, [ebp+16]		; mm1 = 'b'

				movq mm2, mm0			; copy a into mm2 
				pmullw mm0, mm1			; m0 = product low result  "muli packed integer and store low result 
				pmulhw mm1, mm2			; sotre high result into mm1 

				movq mm2, mm0			; mm2 = product low result 
				punpcklwd mm0, mm1		; mm0 = low dword product 
				punpckhwd mm2, mm1		; mm2 = high dword product 

				mov eax, [ebp+24]		; eax =  prod_lo 
				mov edx, [ebp+28]		; edx = prod_hi

				movq [eax], mm0			; save low dword product 
				movq [edx], mm2			; save high dword product 

				pop ebp 
				ret 
MmxMultiply		endp
end 