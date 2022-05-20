GLOBAL cpuVendor
GLOBAL rtcGetter
GLOBAL test

section .text
	
cpuVendor:
	push rbp
	mov rbp, rsp

	push rbx

	mov rax, 0
	cpuid


	mov [rdi], ebx
	mov [rdi + 4], edx
	mov [rdi + 8], ecx

	mov byte [rdi+13], 0

	mov rax, rdi

	pop rbx

	mov rsp, rbp
	pop rbp
	ret

rtcGetter:
	; Recibe como parametro en dil (parte baja de rdi) un char que corresponde al tipo de dato que quiero del RTC. Lo devuelve en hexa.

	push rbp
	mov rbp, rsp

	mov al, dil
	out 0x70, al
	in al, 0x71

	mov rsp, rbp
	pop rbp
	ret
	
test:
    push rbp
    mov rbp, rsp

    mov rax, 2
    mov rdi, 1
    mov rsi, str1
    mov rdx, len1

    int 80h

    mov rsp, rbp
    pop rbp
    ret
    
section .data
str1 db "pito2", 0
len1 equ $-str1-1


