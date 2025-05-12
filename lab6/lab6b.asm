; lab6b.asm: 64-bit NASM program for CS205
; Implements abs_value function to compute absolute value of an integer
; Main calls function, sets result as exit code

section .text
    extern exit                    ; C library exit function
    global _start

; Function: abs_value
; Arg: rdi (integer)
; Returns: rax (absolute value)
abs_value:
    mov rax, rdi                   ; rax = input
    cmp rax, 0                     ; Compare with 0
    jge done                       ; If >= 0, keep as is
    neg rax                        ; If < 0, negate (rax = -rax)
done:
    ret                            ; Return |input| in rax

_start:
    ; Call abs_value(-42)
    mov rdi, -42                   ; Input argument
    call abs_value                 ; rax = |input| (42)

    ; Exit with result as return value
    mov rdi, rax                   ; rdi = result
    call exit
