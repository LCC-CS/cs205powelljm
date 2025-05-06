; lab5a.asm: 64-bit NASM program for CS205
; Prints a Caesar Cipher of "Greetings CS205" (shift letters by 3, skip non-letters)
; Uses printf to display the result

section .data
    ; Memory layout
    input_str db "Greetings CS205", 0    ; Input string (null-terminated)
    output_str times 16 db 0         ; Buffer for encrypted string (15 chars + null)
    shift_amount equ 3               ; Caesar Cipher shift (3 places)
    fmt db "Encrypted: %s", 10, 0    ; Format string for printf

section .text
    extern printf
    extern exit
    global _start

_start:
    ; Initialize registers
    xor ebx, ebx                  ; rbx = index (0)
    mov rsi, input_str            ; rsi = input_str address
    mov rdi, output_str           ; rdi = output_str address

cipher_loop:
    ; Get current character
    mov al, [rsi + rbx]           ; al = input_str[i]
    cmp al, 0                     ; Check for null terminator
    je done                       ; If null, exit loop

    ; Check if character is a letter
    cmp al, 'A'
    jl skip                       ; If < 'A', skip
    cmp al, 'Z'
    jle uppercase                 ; If 'A' to 'Z', process uppercase
    cmp al, 'a'
    jl skip                       ; If < 'a' and > 'Z', skip
    cmp al, 'z'
    jg skip                       ; If > 'z', skip

    ; Lowercase letter ('a' to 'z')
    add al, shift_amount          ; Shift by 3
    cmp al, 'z'
    jle store                     ; If <= 'z', store
    sub al, 26                    ; Wrap around (e.g., 'z' + 3 → 'c')
    jmp store

uppercase:
    ; Uppercase letter ('A' to 'Z')
    add al, shift_amount          ; Shift by 3
    cmp al, 'Z'
    jle store                     ; If <= 'Z', store
    sub al, 26                    ; Wrap around (e.g., 'Z' + 3 → 'C')

store:
    mov [rdi + rbx], al           ; Store shifted char in output_str[i]

skip:
    inc rbx                       ; Increment index
    jmp cipher_loop               ; Next character

done:
    mov byte [rdi + rbx], 0       ; Null-terminate output_str

    ; Print encrypted string
    mov rdi, fmt                  ; 1st arg: format string
    mov rsi, output_str           ; 2nd arg: output_str
    xor rax, rax                  ; No floating-point args
    call printf

    ; Exit
    mov rdi, 0
    call exit
