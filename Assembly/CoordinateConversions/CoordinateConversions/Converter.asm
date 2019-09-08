.model flat, c

.const 
DegToRad	real8		0.017453229252 
RadToDeg	real8		57.2957795131

.code 
RectToPolar		proc
				push ebp
				mov ebp, esp 

				fld real8 ptr[ebp + 16] ; loads y 
				fld real8 ptr[ebp+8]		; loads x for us 

				; find the arc tange of y over x 
				fpatan						; calc atan2(y/x). partial arch tangent instruction 

				fmul[RadToDeg]			; converts the angle at st0 from radians to degrees 
				mov eax, [ebp+28]

				fstp real8 ptr[eax]		; save eax to the fpu stack 

				fld real8 ptr[ebp+8]	; reload x 
				fmul st(0),st(0)		; squares x 

				fld real8 ptr[ebp+16]	; loads y onto the top of the fpu stack and squares it 
				fmul st(0),st(0)

				faddp					; gives us x*x + y*y. adds st0 and st1 

				fsqrt					; gives us the sqrt(x*x + y*y)

				mov eax, [ebp + 24]
				fstp real8 ptr[eax]

				pop ebp 
				ret 

RectToPolar		endp 
PolarToRect		proc 
				push ebp 
				mov ebp, esp 

				fld real8 ptr[ebp+16] ; loads the angle in degrees 
				
				fmul [DegToRad]			; converts from degrees to radians 

				; calculate both the sign and the cos of the value in st0 which is the angle 
				fsincos ; calc sin(st0 and cos(st0)) and pushes them onto the stack in that order 
				fmul real8 ptr[ebp+8]			; y = r * cos(a) - it is the cod because cos is stored at st0 and sin is stored at st1 

				mov eax, [ebp+24]
				fstp real8 ptr[eax]

				fmul real8 ptr [ebp+8] ; find the y value. y = r* sin(a)

				mov eax, [ebp+28]
				fstp real8 ptr[eax] ; saves the valuse of y 

				pop ebp 
				ret 

PolarToRect		endp
end