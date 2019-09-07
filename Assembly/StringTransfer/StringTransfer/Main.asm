.386 
.model flat

.data 
quote	BYTE	"Machines do feel", 0
message BYTE	SIZEOF quote DUP(0),0 ; size fo quote, number of bytes, initilized it to zero 

.code
start		proc 
			mov esi, 0 ; set index to zero 
			mov ecx, SIZEOF quote ; set the counter to the top of quote 

LP: 
			mov al, quote[esi] ; get character from quote
			mov message[esi], al ; put that character into message 
			inc esi ; increment esi, the index register 
			loop LP ; I'm assuming loop checks what esi is at 

			ret

start		endp 
end			