.386
.model flat, c
EXTRN K:dword
.data
MULT dw 8
DIVI dw 2
.code
calc PROC
    push ebp
	mov ebp, esp
	mov eax, dword ptr [ebp+8]
	imul MULT
	sub eax, dword ptr [ebp+12]
	mov ebx, eax
	mov eax, dword ptr [ebp+16]
	idiv DIVI
	add eax, ebx
	add eax, K
	pop ebp
	ret
calc ENDP
END