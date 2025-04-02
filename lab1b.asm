section .data
    hello db "Hello, World!", 10  ; The string with a newline (ASCII 10)
    hello_len equ $ - hello       ; Calculate the length of the string

section .text
    global _start                ; Entry point for the linker

_start:
    ; Write system call (sys_write)
    mov rax, 1         ; syscall: sys_write
    mov rdi, 1         ; file descriptor 1: stdout
    mov rsi, hello     ; pointer to the string
    mov rdx, hello_len ; length of the string
    syscall            ; invoke the system call

    ; Exit system call (sys_exit)
    mov rax, 60        ; syscall: sys_exit
    xor rdi, rdi       ; status 0
    syscall            ; invoke the system call

