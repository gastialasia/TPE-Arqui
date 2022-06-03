GLOBAL sys_write
GLOBAL sys_read
GLOBAL sys_printMem
GLOBAL sys_clear
GLOBAL sys_date
GLOBAL sys_sleep
GLOBAL sys_setScreen
GLOBAL sys_inforeg
GLOBAL divzero
GLOBAL opcode

section .text

sys_write:          ; Los registros de rdi, rsi y rdx ya están cargados por los parámetros de C
    mov rax,2
    int 80h
    ret

sys_read:
    mov rax,1
    int 80h
    ret

sys_printMem:
    mov rax,4
    int 80h
    ret

sys_clear:
    mov rax,3
    int 80h
    ret

sys_date:
    mov rax, 6
    int 80h
    ret

sys_sleep:
    mov rax, 7
    int 80h
    ret

sys_setScreen:
        mov rax, 8
        int 80h
        ret

sys_inforeg:
    mov rax, 5
    int 80h
    ret

divzero:
  xor rax, rax
  div rax
  ret

opcode:
  ud2   ;undefined instruction, para tirar el opcode exception.
  ret
