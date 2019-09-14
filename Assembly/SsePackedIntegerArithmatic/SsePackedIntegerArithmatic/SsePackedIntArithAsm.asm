.model flat, c

.code 
SsePackedInt16_add	proc 
		push ebp
		mov ebp, esp 

		;load the variables 
		mov eax, [ebp+8]  ; eax = pointer to a 
		mov ecx, [ebp+12]	; ecx = pointer to b 
		mov edx, [ebp+16]	; edx = pointer to c 

		movdqa xmm0, [eax]  ; xmm0 = a 
		movdqa xmm1, xmm0
		movdqa xmm2, [ecx]	; xmm2 = b 

		paddw	xmm0, xmm2	; packed addition 
		paddsw	xmm1, xmm2	; packed add saturated  

		movdqa	[edx], xmm0	; save the wrap around c[0]
		movdqa	[edx + 16], xmm1	; save the result of the saturated c[1]

		pop ebp 
		ret 
SsePackedInt16_add	endp 
end