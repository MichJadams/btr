.model flat, c 
.const 
LsEpsilon	real8 1.0e-12
public LsEpsilon
.code 
CalcLeastSquaresAsm	proc 
			push ebp
			mov ebp, esp
			sub esp, 8 

			xor eax, eax
			mov ecx, [ebp+16] ; ecx = n
			test ecx, ecx 
			jle Done

			mov eax, [ebp+8] ; x
			mov edx, [ebp+12] ;x

			fldz ; sum_xx = 0 
			fldz ; sum_xy = 0 
			fldz ; sum_y = 0
			fldz ; sum_x = 0 

			; the stack = sum_x, sum_y, sum_xy, sum_xx x87 fpu register stack 

@@:
			fld real8 ptr[eax] ; x value 
			fld st(0)
			fld st(0)
			fld real8 ptr [edx] ; y value
			; the stack = y, x, sum_x, sum_y, sum_xy, sum_xx x87 fpu register stack 

			fadd st(5), st(0) ; add y to sum_y 
			fmulp 
			; the stack = x(y?), x, sum_x, sum_y, sum_xy, sum_xx x87 fpu register stack 
			
			faddp st(5), st(0) ; add sum_xy += xy 
			; the stack = x, x, sum_x, sum_y, sum_xy, sum_xx x87 fpu register stack 
			fadd st(2), st(0) ; add sum_x to x 
			; the stack = xx, sum_x, sum_y, sum_xy, sum_xx x87 fpu register stack 
			fmulp

			faddp st(4), st(0) ; add sum_xx to xx 
			; the stack = sum_x, sum_y, sum_xy, sum_xx x87 fpu register stack 

			add eax, 8 
			add edx, 8 
			dec ecx
			jnz @B

			; 	double denom = n * sum_xx - sum_x * sum_y; 
			fild dword ptr [ebp + 16]
			fmul st(0), st(4) 
			; the stack = sum_xx * n, sum_x, sum_y, sum_xy, sum_xx x87 fpu register stack 

			fld st(1) 
			fld st(0)
			; the stack = sum_x,sum_x, sum_xx * n, sum_x, sum_y, sum_xy, sum_xx \\ x87 fpu register stack 

			fmulp
			fsubp
			fst real8 ptr[ebp-8] ; saves the denom 

			; the stack = denom, sum_x, sum_y, sum_xy, sum_xx

			fabs	; get the floating point abs value of the top of the stack 
			fld real8 ptr[LsEpsilon]
			fcomip st(0), st(1)
			fstp st(0)
			jae InvalidDenom ; jump if st(1) >= st(0) 
			
			fild dword ptr[ebp + 16]

			fmul st(0), st(3) ; n * sum_xy
			fld st(2)		; sum_y 
			fld st(2)		; sum_x 

			fmulp			; sum_x * sum_y 
			fsubp			; n * sum_cy - sum_x * sum_y 
			fdiv real8 ptr[ebp-8]
			mov eax, [ebp+20]
			fstp real8 ptr[eax]
			
			; intercept 
			;	*b = (sum_xx * sum_y - sum_x * sum_xy) / denom; 

			fxch st(3) 
			fmulp 
			fxch st(2) 
			fmulp 
			fsubp 
			fdiv real8 ptr[ebp-8]
			mov eax, [ebp+24]
			fstp real8 ptr [eax]

			mov eax, 1


Done:
			mov esp, ebp
			pop ebp

			ret 

InvalidDenom:
; clean up the fpu stack 
			fstp st(0)
			fstp st(0)
			fstp st(0)
			fstp st(0)
			xor eax, eax
			; could probably jump to Done at this point 
			mov esp, ebp 
			pop ebp
			ret 
CalcLeastSquaresAsm endp 
end 