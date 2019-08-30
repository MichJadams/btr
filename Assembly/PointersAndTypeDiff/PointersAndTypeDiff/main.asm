.386 

.model flat 

;create some custom pointers 
ptrByte TYPEDEF  PTR BYTE 
ptrWord TYPEDEF PTR word 
ptrDword TYPEDEF PTR dword 

.data 
arrayb  BYTE 10h,20h,30h
arrayw	word 1,2,3
arrayd	dword 4,5,6

pt_1 ptrByte  arrayb 
pt_2 ptrWord arrayw 
pt_3 ptrDword arrayd 

.code 

main proc 

	mov esi, pt_1
	mov al, [esi] ; al should have the value 10, al is the lower bit of the ax register. AX is a 16 bit register adn eax is 32 bit
	mov esi, pt_2 
	mov ax, [esi]
	mov esi, pt_3
	mov eax, [esi]

	ret 
main endp 
end main 
