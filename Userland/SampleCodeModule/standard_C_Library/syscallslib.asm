GLOBAL sys_write

section .text

sys_write:          ; Los registros de rdi, rsi y rdx ya están cargados por los parámetros de C
    mov rax,2
    int 80h
    ret

sys_read:
    mov rax,1
    int 80h
    ret