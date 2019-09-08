.model flat, c 

.const 
r4_minFloat		dword 0ff7fffffh ; smallest floating point 
r4_maxFloat		dword 7f7fffffh; largest floating point 


.code
CallMinMax	proc 
					push ebp
					mov ebp, esp

					xor eax, eax  ; check if the array has length

					;check inputs are valid 
					mov edx, [ebp+8]	; edx = a 
					mov ecx, [ebp+12] ; ecx = n 
					test ecx, ecx 
					jle Done

					; initilize our constants up top 
					fld [r4_minFloat]
					fld [r4_maxFloat]
					

					
@@:
					fld real4 ptr[edx]		; put a on the stack 
					fld st(0)				; duplicate *a on the stack 

					fcomi st(0), st(2)		; compare *a with r4_minFloat (which is at st2) 
					fcmovnb st(0), st(2)	; the smallest value gets placed into st(0) 
					fstp	st(2)			; save new min value to the stack 

					fcomi st(0), st(2)		; compare a* with max 
					fcmovb st(0), st(2)	; sets st(0) = larger value 
					
					fstp st(2)				; save new max value 


					add edx, 4
					dec ecx 
					jnz @B

					mov eax, [ebp+16]
					fstp real4 ptr[eax]
					mov eax, [ebp+20]
					fstp real4 ptr[eax]
					mov eax, 1
Done: 
					pop ebp 
					ret 
CallMinMax	endp 
end