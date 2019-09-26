.386
.model flat

.data 
ArrayToSort		dw	5,4,10,2,1

.code 
QuickSort		proc 

		mov		edi, OFFSET ArrayToSort 
		mov		ecx, LENGTHOF ArrayToSort 
		mov		eax, 0
		mov		edx, ecx
		sar		edx, 1	; divide esi by 2 

		; eax = low value
		; ecx = high value
		; edx = pivot
Partition: 
		mov		edx, dword ptr ArrayToSort[ecx]	; pivot = arr[high]
		sub		eax, 1							; i = the index of the smaller element

PartitionLoop:

		cmp		edx, dword PTR ArrayToSort[ecx]	; compare the pivot to the current element 

		;if the current element is smaller than the pivot 
		jg		Swap							; jump to swap if the item is greater than the pivot
	
		loop	PartitionLoop					; loop uses the ecx register to count down its looping
		
		;
		jmp Sort
Swap:
		; swap the two using exchange 
		; incremenet the index of the smaller element (low)
		inc		eax
		;swap the array at edx and eax, using the stack? yess.....
		push  ArrayToSort[eax]
		push  ArrayToSort[edx]

		pop  ArrayToSort[eax]
		pop  ArrayToSort[edx]
	

		jmp		Partition
		
Sort: 
			ret
QuickSort		endp
end


;
;def partition(arr,low,high): 
    ;i = ( low-1 )         # index of smaller element 
    ;pivot = arr[high]     # pivot 
  ;
    ;for j in range(low , high): 
  ;
        ;# If current element is smaller than the pivot 
        ;if   arr[j] < pivot: 
          ;
            ;# increment index of smaller element 
            ;i = i+1 
            ;arr[i],arr[j] = arr[j],arr[i] 
  ;
    ;arr[i+1],arr[high] = arr[high],arr[i+1] 
    ;return ( i+1 ) 
  ;
;# The main function that implements QuickSort 
;# arr[] --> Array to be sorted, 
;# low  --> Starting index, 
;# high  --> Ending index 
  ;
;# Function to do Quick sort 
;def quickSort(arr,low,high): 
    ;if low < high: 
  ;
        ;# pi is partitioning index, arr[p] is now 
        ;# at right place 
        ;pi = partition(arr,low,high) 
  ;
        ;# Separately sort elements before 
        ;# partition and after partition 
        ;quickSort(arr, low, pi-1) 
        ;quickSort(arr, pi+1, high) 