section .text
    global ft_strcpy

; char *strcpy(char *dest, const char *src);
; dest is in rdi and src is in rsi
ft_strcpy:
    xor ecx, ecx ; Initialize counter to 0

cpy_loop:
    mov al, [rsi + rcx] ; Load byte from src
    mov [rdi + rcx], al ; Move the byte to dest

    test al, al ; Check the end of rsi, i.e. src
    jz end ; If zero (end of string), end comparison

    inc rcx ; Increment counter
    jmp cpy_loop ; Continue loop

end:
    mov rax, rdi ; Move dest to rax
    ret ; Return in rax
