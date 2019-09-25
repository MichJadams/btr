.386
.model flat

.data 
ArrayToSort		BYTE	3,2,1,6,7

.code 
QuickSort		proc 

		mov		edi, OFFSET ArrayToSort 
		mov		ecx, LENGTHOF ArrayToSort 
		mov		eax, 0
		mov		edx, ecx
		sar		edx, 1	; divide esi by 2 

Partition: 
		mov		al, BYTE PTR ArrayToSort[edx]	; this is the pivot
		cmp		[edi], al						; compare the pivot to the current element 
		jg		Swap							; jump to swap if the item is greater than the pivot
	
		loop	Partition						; loop uses the ecx register to count down its looping
		jmp Sort
Swap:
; swap the two using exchange 
		mov		ah, [edi]
		mov		[edi], al 
		mov		BYTE PTR ArrayToSort[edx], ah 
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