.model flat, c

.const 
R8_4p0	real8	4.0
R8_3p0	real8	3.0

;extern "C" bool SphereAreaAndVolume(int radius, int* sa, double* v);
; surface area = 4pi * radius squared 
; volume = 4pir^3/3 = (4piR^2)r/3
.code
SphereAreaAndVolume	proc 
					push ebp
					mov ebp, esp

					xor eax, eax  ; holds the radius entered by the user. Checks if eax is 0 
					fld real8 ptr[ebp+8] ; push the argument entered by the used onto ST(0) = r 
					fldz					; ass 0 onto the stack st(0) = 0.0 and st(1) = r 
					fcomip st(0),st(1)	; compares 0 to r. 
					fstp st(0) ; removes r from the stack? but why? 

					;jump if unordered operands
					jp done
					; jump if r < 0.0 
					ja done 

					fld  real8 ptr[ebp + 8] ; reload r 
					fld st(0)			; ST(0)=r, ST(1)=r

										;square the radius amd save it in st(0) 
					fmul st(0), st(0)	; ST(1)=r ST(0)=r^2,

					fldpi				; ST(0) = pi, ST(1) = r^2 and ST(2) = r 

					fmul [R8_4p0]		; automatically stores the result back into zero 
					fmulp				; ST(0) = 4*pir*r*r

					mov edx, [ebp+16]
					fst real8 ptr[edx]	; save the surface area from edx to the caller function 

										; volume computation
					fmulp				;ST(0) = pir*4*r*r*
					fdiv [R8_3p0]		;ST(0) = pir*4*r*r*/3

					mov edx, [ebp + 20]
					fst real8 ptr[edx] ; saving 

					mov eax, 1
done:
					pop ebp
					ret

SphereAreaAndVolume	endp 
end