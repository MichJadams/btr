.model flat, c
.code 
CalcArrayRowColSum		proc 
						push ebp 
						mov ebp, esp
						push ebx
						push esi 
						push edi 

						;check args
						xor eax, eax 
						cmp dword ptr[ebp + 12], 0
						jle invalidArg

						mov ecx, [ebp + 16]
						cmp ecx, 0  ; why not cmp, [ebp + 16], 0  ??
						jle invalidARg 

						mov edi, [ebp + 24 ]
						xor eax, eax 
						rep stosd    ; fills the array in edi with zeros. uses ecx as a vounter until ecx is zero 

						mov ebx, [ebp+8]
						xor esi, esi  ; i = 0 
Lp1:
						; outer loop 
						mov edi, [ebp+20] ; row sum array 
						mov dword ptr[edi + esi + 4], 0  ; row_sums[i] = 0 
						xor edi, edi ; makes j = 0  
						mov edx, esi ; edx = i 
						imul edx, [ebp +16] ; edx = i *ncol 
 Lp2:
						;inner loop
						mov ecx, edx 
						add ecx, edi ; ecx = i*ncol+index j 
						mov eax, [ebx+ecx*4] ; eax = x[i*nolcol +j]
						mov ecx, [ebp+20]
						add [ecx + esi * 4], eax ; rowsums at i + eax 
						mov ecx, [ebp+24] ; 
						add [ecx+edi*4], eax 

						inc edi; j++
						cmp edi, [ebp+16] ; compare j to the numer of columns 
						jl Lp2

						inc esi
						cmp esi, [ebp+12]
						jl Lp1
						
						mov eax, 1

invalidArg: 
						pop edi 
						pop esi
						pop ebx 
						pop ebp

						ret 

CalcArrayRowColSum		endp 
end 