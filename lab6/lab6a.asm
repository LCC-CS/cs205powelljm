; lab6a.asm: 64-bit NASM program for CS205
; Implements add_three function to sum three arguments
; Main calls function, sets sum as exit code

section .text
    extern exit                    ; C library exit function
    global _start

; Function: add_three
; Args: rdi (first), rsi (second), rdx (third)
; Returns: rax (sum)
add_three:
    mov rax, rdi                   ; rax = first arg
    add rax, rsi                   ; rax += second arg
    add rax, rdx                   ; rax += third arg
    ret                            ; Return sum in rax

_start:
    ; Call add_three(10, 20, 30)
    mov rdi, 10                    ; First arg
    mov rsi, 20                    ; Second arg
    mov rdx, 30                    ; Third arg
    call add_three                 ; rax = sum (60)

    ; Exit with sum as return value
    mov rdi, rax                   ; rdi = sum
    call exit
