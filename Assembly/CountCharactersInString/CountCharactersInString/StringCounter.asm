.model flat, c
.code 

;extern "C" int CountChars_(wchar_t* s, wchar_t c); 

CountChars_		proc
		push ebp
		mov ebp, esp 
		push esi 

		;get the variables 
		mov esi, [ebp+8] ; load the pointer to the string we are looking  through  s
		mov cx, [ebp+12] ; load the character we are looking for  c 

		xor edx, edx ; this is our counter for the number of occurances. Zero it out 

@@:
		lodsw		; load next character into ax. loads whatever esi is pointing to into ax, then incrmenets esi by two 
					; use lodsb for normal strings, 
		or ax, ax	; test for end of string with or 
		jz @F		; jump if xor does not equal zero . jump if zero returned from or 
		cmp ax, cx  ; compare the chracter in ax, to the character we are looking for, which is stored in cx
		jne @B		; jump not equal 
		inc edx
		jmp @B		;just jump 

@@: 
		mov eax, edx   ; edx = character count 
		pop esi 
		pop ebp 

		ret

CountChars_		endp
end 