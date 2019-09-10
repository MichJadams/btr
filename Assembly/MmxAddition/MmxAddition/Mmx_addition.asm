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



BadAddOp:

			ret
		align 4 
AddOpTable:
		dword MmxPaddb, MmxPaddsb, MmxPaddusb,
		dword MmxPaddw, MmxPaddsw, MmxPaddusw, MmxPaddd

AddOpTableCount equ($-AddOpTable) / size dword 


MmxAdd	endp
		end 