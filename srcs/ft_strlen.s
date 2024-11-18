section .text
global ft_strlen

; size_t strlen(const char *s);
; s is stored in rdi
ft_strlen:
    xor rax, rax  ; Initialize counter to 0

loop_str:
    cmp byte [rdi + rax], 0 ; Compare byte at [rdi + rax] with 0
    je end  ; If it's 0, jump to end

    inc rax  ; Increment counter
    jmp loop_str  ; Continue loop

end:
    ret  ; Return, length is in rax
