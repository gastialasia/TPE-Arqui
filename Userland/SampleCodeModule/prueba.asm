GLOBAL test

section .text

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
len1 equ $ - str1