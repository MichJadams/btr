.model flat, c 
.code 

MmxShiftAsm		proc 
			push ebp
			mov ebp, esp 

			xor eax, eax
			mov edx, [ebp+16]	; shift operator passed in by user 
			cmp edx, ShiftOpTableCount 
			jae	BadShiftOp

			mov eax, 1 
			movq mm0, [ebp+8]	; load a 
			movd mm1, dword ptr[ebp+20]; loads the count into low dword 
			jmp [ShiftOpTable+edx*4]
MmxPsllw:	
			psllw mm0, mm1 
			jmp saveResult
MmxPsrlw:
			psrlw mm0, mm1
			jmp saveResult 
MmxPsraw:
			psraw mm0, mm1
			jmp saveResult 
MmxPslld:
			pslld mm0, mm1
			jmp saveResult
MmxPsrld:
			psrld mm0, mm1
			jmp saveResult
MmxPsrad: 
			psrad mm0, mm1 
			jmp saveResult

BadShiftOp:
			pxor mm0, mm0
saveResult:
			mov edx, [ebp+24] ; load b 
			movq [edx], mm0	; 
			emms			;clear mmx state 
			pop ebp 

			ret 
			align 4 

ShiftOpTable: 
dword MmxPsllw,  MmxPsrlw,	MmxPsraw,  MmxPslld,	MmxPsrld,	MmxPsrad

ShiftOpTableCount	equ($- ShiftOpTable)/size dword 

MmxShiftAsm		endp 
end 