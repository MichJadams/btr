.model flat, c
.code
MmdAdd		proc 
			push ebp
			mov ebp, esp

			mov eax, [ebp+24]			; loads add_op for us 
			cmp eax, AddOpTableCount	; check length of table count
			jae BadAddOp

			movq mm0, [ebp+8]			; loads a into mm0. move means move quad word
			movq mm1, [ebp+16]			; gets second param
			jmp [AddOpTable + eax * 4]	; jump to the specified add operation 

MmxPaddb:	paddb mm0, mm1				; packed byte addition using wrap around 
			jmp saveResult

MmxPaddsb:	paddsb mm0,mm1				; packed byte addition using signed saturation 
			jmp saveResult

MmxPaddusb:	paddusb mm0,mm1				; packed byte addition using unsigned saturation 
			jmp saveResult

MmxPaddw:	paddw mm0,mm1				; packed word addition using wrap around 
			jmp saveResult
			
MmxPaddsw:	paddsw mm0,mm1				; packed word addition using signed wrap around 
			jmp saveResult

MmxPaddusw:	paddusw mm0,mm1				; packed word addition using unsigned saturation
			jmp saveResult

MmxPaddd:	paddd mm0,mm1				; packed word addition using signed wrap around 
			jmp saveResult


BadAddOp:
			pxor mm0, mm0 ; if invalid operation is detected we clear the register mm0

saveResult:
			movd eax, mm0 ; eax = low dword of mm0 because eax cant hold the whole thing 
			pshufw mm2, mm0, 01001110b	; swap 7 high and low dwords. each 2 bit filed equals a 2 bit field destination 
			movd edx, mm2			; we have the final result in edx and eax . edx : eax = final result 
			emms					;clea mmx state 
			pop ebp
			ret

		align 4 

AddOpTable: 
		dword MmxPaddb, MmxPaddsb, MmxPaddusb,
		 MmxPaddw, MmxPaddsw, MmxPaddusw, MmxPaddd

AddOpTableCount equ($-AddOpTable) / size dword 


MmdAdd	endp
		end 