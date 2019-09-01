.386 
.model flat, c
.code 


calculateSum	proc 
		push ebp
		mov ebp, esp
		sub esp, 12 ; allocate some local storage for ourselves 

		; preserve the non-volitile registers
		push ebx
		push esi
		push edi 

;load arguments 
		mov eax, [ebp + 8] ; param a 
		mov ebx, [ebp + 12] ; param b 
		mov ecx, [ebp + 16] ; param c 
		mov edx, [ebp + 20] ; param s1 
		mov esi, [ebp + 24] ; param s2
		mov edi, [ebp + 28] ; param s3 

; compute s1. Add togeather a,b,c
		mov [ebp-12], eax ; ebp-12 is out temp storage space from above. It can hold s1 values for now
		add [ebp-12], ebx ; we could have put it into edx immediately, this is just showing example
		add [ebp-12], ecx ; of local variables 
		
; compute the sum of squares. first square all the registers values. a^2 + v^2 + c^2 = s2  
		imul eax, eax 
		imul ebx, ebx 
		imul ecx, ecx 

; useing temporary storage here again. Add up the new, squared eax, ebx, ecx
		mov [ebp-8], eax 
		add [ebp-8], ebx 
		add [ebp-8], ecx 
; calculate s3. s3 = sum of cubes 

		imul eax, [ebp + 8]  ; use the original value of the param a, which is stored in [ebp + 8]. 
		; now eax holds the cube of a
		imul ebx, [ebp + 12] 
		imul ecx, [ebp + 16] 

		mov [ebp-4], eax 
		add [ebp-4], ebx 
		add [ebp-4], ecx 

		; why doesn't this work?
		;mov edx,  [ebp-12]
		;mov esi, [ebp-8]
		;mov edi, [ebp-4]
		
		; saving s1, s2 and s3. Use eax as an intermediary 
		mov eax, [ebp-12]
		mov [edx], eax

		mov eax, [ebp-8]
		mov [esi], eax

		mov eax, [ebp-4]
		mov [edi], eax

		;epilogue. Restores the non volitile registed esi, edi and ebx 
		pop edi
		pop esi
		pop ebx
		mov esp, ebp ; frees up out local storage. Not sure how 
		pop ebp

		ret 
calculateSum endp 
end 


