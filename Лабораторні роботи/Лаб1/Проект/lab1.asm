.586

.model flat, stdcall
option casemap: none

include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\masm32.inc
include \masm32\include\debug.inc
include \masm32\include\user32.inc 

includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\masm32.lib
includelib \masm32\lib\debug.lib
includelib \masm32\lib\user32.lib

.data
Arr dd 1,2,3,4,5
B dd 1
D dd 1

.code
start:
    mov ebx, 0
    mov ecx, 0
prnt:
    mov eax, [Arr+ecx*4]
    cmp eax, B
    jl next
    cmp eax, D
    jg next
    add ebx, eax
    PrintDec eax, "Arr value"
next:
    inc ecx
    cmp ecx, 5
    jnz prnt
    PrintDec ebx, "Sum"
    invoke ExitProcess, NULL
end start