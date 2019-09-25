.386
.model flat, stdcall
option casemap :none

extrn MessageBoxA@16 : PROC
extrn ExitProcess@4 : PROC

.data
    HelloWorld db "Welcome to Pong", 0
    MsgTitle db "Welcome", 0

.code
main:

    mov eax, 0
    push eax

    lea ebx, MsgTitle
    push ebx

    lea ebx, HelloWorld
    push ebx
    push eax

    call MessageBoxA@16
    push eax
    call ExitProcess@4


end main