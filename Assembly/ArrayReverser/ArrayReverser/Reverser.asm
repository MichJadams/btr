.386 
.model flat , c
.code 

Reverser	proc  ; set up the prolog of the function 
			push ebp
			mov ebp, esp 
			push esi
			push edi



			xor eax, eax ; access params from cpp code 
			mov edi,[ebp+8]
			mov esi,[ebp+12] ; grabbing second param, offset of 12
			mov ecx,[ebp+16] ; grab third param from Reverser and put it in ecx
			test ecx,ecx

			lea esi,[esi+ecx*4-4]
			pushfd
			std

@@:			lodsd   ;create a loop
			mov [edi],eax
			add edi,4
			dec ecx
			jnz @B

			popfd    ; pop the flag value 
			mov eax, 1 ; set eax equal to 1 

			pop edi ; set up the epilogue 
			pop esi 
			pop ebp

			ret

Reverser	endp
			end			
