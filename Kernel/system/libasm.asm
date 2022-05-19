GLOBAL cpuVendor
GLOBAL rtcGetter
GLOBAL sys_read
GLOBAL sys_write
GLOBAL sys_memdump
GLOBAL sys_date
GLOBAL sys_regdump


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

sys_read:

	
	

sys_write:
	push rbp
	mov rbp,rsp
	
	call ncPrintChar

sys_memdump:

sys_date:

sys_regdump:

