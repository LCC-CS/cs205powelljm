; Simple 64-bit NASM program to sum an array of integers
; Target: 64-bit Linux, using C library (printf)
; Sums [1, 2, 3, 4, 5] and prints result

section .data
    ; Memory layout
    array dd 1, 2, 3, 4, 5    ; Array of 5 integers (4 bytes each)
    array_len equ 5           ; Length of array
    sum dd 0                  ; Sum variable (4 bytes)

    ; Format string for printf
    fmt db "Sum of array: %d", 10, 0  ; 10 = newline

section .text
    ; External C library functions
    extern printf
    extern exit

    global _start

_start:
    ; Initialize sum
    mov dword [sum], 0        ; Clear sum variable
    xor ebx, ebx              ; Clear rbx for running sum

    ; Loop setup
    mov ecx, array_len        ; Counter (5 iterations)
    mov rsi, array            ; rsi = pointer to array start

loop_start:
    ; Add array element to sum
    add ebx, [rsi]            ; rbx += array[i] (4-byte load)
    add rsi, 4                ; Next element (4 bytes)
    dec ecx                   ; Decrement counter
    jnz loop_start            ; Loop if ecx != 0

    ; Store sum
    mov [sum], ebx            ; Save result to memory

    ; Print sum with printf(fmt, sum)
    mov rdi, fmt              ; 1st arg: format string
    mov esi, ebx              ; 2nd arg: sum (32-bit)
    xor rax, rax              ; No floating-point args
    call printf

    ; Exit with code 0
    mov rdi, 0
    call exit
