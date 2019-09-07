.model flat, c 

.data 

.const 
; these are labels
r8_sfFtoC	real8	0.5555555556  ; 5/9 
r8_sfCtoF	real8	1.8 ; 9/5 
i4_32		dword	32 ; would have been more effiencet to use real8

.code 
; f to c  - 32 * 5  then divide by 9 
;extern "C" double FtoCAsm(double degreeF);
FtoCAsm		proc
			push ebp
			mov ebp, esp 
			
			;use flb instruction 
			fld [r8_sfFtoC] ; pushed this constant onto the stack 
			fld real8 ptr[ebp + 8] ; gives first argument in function. real8 says it is a local percision flaoting point number 
			fild[i4_32] ; loads 32 on to the stack of fld 

			; these just handel the saing themselves...
			fsubp ; ST(0) = f-32
			fmulp ; ST(0) = f - 32 * 5/9
			; st(0) contains the result and is the only item on the stack. 

			pop ebp
			ret

FtoCAsm		endp

; from c to c *9 then divide by 5 then add 32
;extern "C" double CtoFAsm(double degreeC);
CtoFAsm		proc
			push ebp
			mov ebp, esp 
			
			fld real8 ptr[ebp + 8] 
			fmul [r8_sfCtoF]
			fiadd [i4_32] ;ST(0) c * 9/5 - 32
			
			pop ebp
			ret
CtoFAsm		endp
end 
