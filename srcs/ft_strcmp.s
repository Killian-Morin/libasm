section .text
global ft_strcmp

; int strcmp(const char *s1, const char *s2);
; s1 is in rdi, s2 is in rsi
ft_strcmp:
    xor rcx, rcx

cmp_loop:
    mov al, [rdi + rcx] ; Load byte from s1
    mov dl, [rsi + rcx] ; Load byte from s2

    cmp al, dl ; Compare characters
    jne end ; If not equal, end comparison

    test al, al ; Check the end of s1
    jz end ; If zero (end of string), end comparison

    inc rcx ; Move to next character
    jmp cmp_loop ; Continue loop

end:
    movsx eax, al ; Sign-extends al to eax
    movsx edx, dl ; Sign-extends dl to edx
    sub eax, edx ; Substract to get the difference
    ret ; Return result in eax
