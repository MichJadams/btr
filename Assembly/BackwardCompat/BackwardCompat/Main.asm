;------------x86 64 bit (also known as x64), make sure to change in 
; visual studio code 
;.code 
;
;Main	 proc 
		;mov rax, 2
		;mov rbx, 3
		;mov rcx, 4
		;ret
;Main	endp
;end

;------------x86 32 bit 
;.386
;.model flat 
;.code 
;Main	Proc
		;mov eax, 2
		;mov ebx, 3
		;mov ecx, 4
		;ret 
;Main	endp 
;end		Main

;------------ 16 bit (sort of), just using the lower 
; 16 bits of the 32 bit register 
.386
.model flat 
.code 
Main	proc
		mov ax, 2
		mov bx, 3
		mov cx, 4
		ret 
Main	endp
end		Main
