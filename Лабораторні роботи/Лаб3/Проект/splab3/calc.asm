.386
.model flat, c
EXTRN   printf:near
.data
fmt1 db "Result = ", 0;
fmt2 db "%lf", 13, 10, 0;
temp qword ?
K equ 7AA02023h; (2057314339d)
.code
calcLab3 PROC
    finit
    push ebp
	mov ebp, esp

	mov dword ptr temp, K
	fild temp
	fld qword ptr [ebp + 8]
	fmul qword ptr [ebp + 16]	;A * B
	fadd						;X = K + A * B

	fld dword ptr [ebp + 24]
	fchs
	fadd						;X = K + A + B - C
	
	fld dword ptr [ebp + 28]
	fdiv qword ptr [ebp + 32]	;D / E
	fadd						;X = K + A * B - C + D / E

		
	fst temp
	mov ecx, dword ptr temp[4]
	mov eax, dword ptr temp[0]
    push ecx; for next call printf
    push eax; for next call printf

    push OFFSET fmt1
    call printf
    add esp, 4

    push OFFSET fmt2
    call printf
    add esp, 12

	pop ebp
	ret

calcLab3 ENDP
END