; array_5x5.asm: 64-bit NASM program for CS205
; Fills a 5x5 array with row*col values, sets exit code to last value (25)

section .data
    array times 25 dd 0           ; 25 integers (4 bytes each), 100 bytes

section .text
    extern exit
    global _start

_start:
    ; Outer loop: rows (i = 1 to 5)
    mov rdi, 1                    ; i = row
row_loop:
    cmp rdi, 5
    jg done
    ; Inner loop: columns (j = 1 to 5)
    mov rsi, 1                    ; j = col
col_loop:
    cmp rsi, 5
    jg next_row
    ; Compute value: rax = i * j
    mov rax, rdi
    mul rsi                       ; rax = i * j
    ; Compute array index: (i-1)*5 + (j-1)
    mov rbx, rdi
    dec rbx                       ; i-1
    imul rbx, 5                   ; (i-1)*5
    mov rcx, rsi
    dec rcx                       ; j-1
    add rbx, rcx                  ; (i-1)*5 + (j-1)
    ; Store value: array[index] = rax
    shl rbx, 2                    ; index * 4 (dword size)
    lea r8, [array]               ; r8 = array base address
    add rbx, r8                   ; rbx = array + index*4
    mov [rbx], eax                ; Store lower 32 bits of rax
    ; Save last value
    mov r10, rax                  ; r10 = last value
    inc rsi
    jmp col_loop
next_row:
    inc rdi
    jmp row_loop
done:
    ; Exit with last value (25)
    mov rdi, r10
    call exit
