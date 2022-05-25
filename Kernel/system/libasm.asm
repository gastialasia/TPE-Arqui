GLOBAL cpuVendor
GLOBAL rtcGetter
GLOBAL test
GLOBAL getRegisters

EXTERN _sti

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

    mov rax, 6
    mov rdi, 4
	
	int 80h

    mov rsp, rbp
    pop rbp
    ret

;section .data
;len1 equ 4
;str2 db "hola",0

;section .bss
;str1 resb 8


getRegisters:
	push rbp
	mov rbp, rsp

	mov [struct_reg], rax
	mov [struct_reg+1*8], rbx
	mov [struct_reg+2*8], rcx
	mov [struct_reg+3*8], rdx
	mov [struct_reg+4*8], rdi
	mov [struct_reg+5*8], rsi
	mov [struct_reg+6*8], rbp
	mov [struct_reg+7*8], rsp
	mov [struct_reg+8*8], r8
	mov [struct_reg+9*8], r9
	mov [struct_reg+10*8], r10
	mov [struct_reg+11*8], r11
	mov [struct_reg+12*8], r12
	mov [struct_reg+13*8], r13
	mov [struct_reg+14*8], r14
	mov [struct_reg+15*8], r15

	mov rax, struct_reg

	mov rsp, rbp
	pop rbp
	ret

section .bss
struct_reg resb 128