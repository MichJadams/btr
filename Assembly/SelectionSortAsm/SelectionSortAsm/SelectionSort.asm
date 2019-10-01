.386
.model flat, stdcall

.data 

ArrayToSort dw	10,9,8,7,6,5,4,2,8,1,1,1 ; the array to be sorted, can hold double word lenght values (32 bit)

.code 

; procedure SelectMin
; PARAMS: edx must hold the begining of the array 
; PARAMS: edi must be the current index to place 

SelectMin proc
		pusha					; push all the registers, to be safe 
		xor eax, eax			; clear eax, which will hold our "main" value to be placed
		xor ebx, ebx			; clear ebx, which will hold the pointer to the "main" value 

		mov ax, [edx+edi*2]		; move the "main" value into the lower half of eax. This is the value the edi pointer is at 
		mov ebx, edi			; save the edi pointer. It will change in the loop, but we need one to be associated to eax
@@:
		sub edi, 1				; decrmenet edi 
		cmp [edx+edi*2], ax		; compare the value at edi and the "main" value 
		jg MoveMin				; jump if the value at edi is less than the main value. They must be switched

		cmp edi, 1				; check if we are at the end of the loop

		jg @b					; continue to loop if edi is greater than or equal to 0
		jmp finish				; jump to the end 

MoveMin: 
		xor ecx, ecx			; clear ecx, we are going to use it to hold an interum value

		mov cx,[edx+edi*2]		; move the value at edi into the holder register cx
		mov [edx+edi*2], ax		; move the "main" value into the place where edi is pointing
		mov [edx+ebx*2], cx		; move the value that was at edi, to where the "main" value WAS before. It's hold index
		mov ebx, edi			; now update the index of the "main" value

		jmp @b					; jump back to the loop
finish:
		popa					; pop all the registers 
		ret 
SelectMin	endp

SelectionSort proc
		mov edx, offset ArrayToSort 
		mov ecx, lengthof ArrayToSort 

		xor edi, edi			; zero out the counter 

@@:
		call SelectMin			; call Select min which moves the value at edi in the array to its proper place to the left
		add edi, 1				; incrmenet the counter by 1, so we don't compare index 0 to index 0  
		
		cmp edi, ecx			; check to see if we have reached the end of our array
		jne @b					; jump back if these two are not equal
		jmp finish				; otherwise jump to the end

finish: 
		nop						; give the debugger a place to rest so you can examin the array sorted in memory
		ret 
SelectionSort endp
end 