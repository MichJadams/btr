.386

.model flat, c 
.data 

ArrayToSort		dword	10, 11, 4, 5, 6
.code 
MergeSort	proc
			mov edi, OFFSET ArrayToSort 
			mov ecx, LENGTHOF ArrayToSort 
			mov eax, 0 

			; create a left half and a right half of the array 
			mov edx ; find the mid point 
					; move one half of the array onto the stack 
					; move the other half onto the stack 

					; create stack 
					; if the subarray is length 2, push it to the stack 
			ret 

MergeSort	endp
end