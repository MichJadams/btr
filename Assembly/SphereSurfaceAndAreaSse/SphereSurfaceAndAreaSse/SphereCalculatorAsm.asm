.model flat, c 
.const 

r8_pi		real8	3.14159265359
r8_four		real8	4.0
r8_three	real8	3.0
r8_neg_one	real8	-1.0

.code
SseSphereCalculatorAsm	proc 
		push	ebp
		mov		ebp, esp

		movsd	xmm0, real8 ptr[ebp+8]	; r
		mov		ecx, [ebp+16]				; ecx = sa
		mov		edx, [ebp+20]				; edx =v

		xorpd	xmm7, xmm7				; made xmm7 = 0.0 
		comisd	xmm0, xmm7				; compare 0 with r 
		jp	BadRadius 
		jb	BadRadius

		; surface area = 4pir^2
		movsd xmm1, xmm0		; xmm1 = r
		mulsd xmm1, xmm1		; squares xmm1
		mulsd xmm1, [r8_four]	; xmm1 = 4*xmm1
		mulsd xmm1, [r8_pi]		; xmm1 = xmm1*pi

		movsd real8 ptr[ecx], xmm1	; saves xmm1 into the poiunter to ecx 

		; compute the volumne 

		mulsd xmm1, xmm0	; xmm1 = surface area, xmm0 = r. now xmm1 = surface area * r 
		divsd xmm1, [r8_three]	; divide xmm1 by three 

		movsd real8 ptr[edx], xmm1 ; save into ecx 

		mov eax, 1 

		pop ebp 
		ret 
BadRadius:	
		movsd	xmm0, [r8_neg_one]
		movsd	real8 ptr[ecx], xmm0	; sa* = -1 
		movsd	real8 ptr[edx], xmm0	; *v = -1 
		xor eax, eax
		pop ebp 
		ret 
SseSphereCalculatorAsm endp 
end 