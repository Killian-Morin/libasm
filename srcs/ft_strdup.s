%define ENOMEM 12

section .text
    global ft_strdup
    extern malloc
    extern __errno_location
    extern ft_strlen
    extern ft_strcpy

; char *strdup(const char *s);
; rdi holds s
ft_strdup:
    push rdi ; Save the source string pointer
    call ft_strlen ; Get length of the string

    inc rax ; Add 1 for null terminator
    mov rdi, rax ; Set as argument for malloc
    call malloc WRT ..plt ; Allocate memory

    test rax, rax ; Check if malloc succeeded
    jz errno ; If malloc failed, return NULL and set errno

    mov rdi, rax ; Set destination for strcpy
    pop rsi ; Restore source string to rsi
    call ft_strcpy ; Copy the string

    ret ; Return, duplicated string is in rax

errno:
    xor rax, rax ; Return NULL
    mov rdi, ENOMEM ; Move error code to rdi (first argument for __errno_location)
    call __errno_location WRT ..plt ; Call __errno_location to get errno address
    mov [rax], rdi ; Store error code in errno
    ret
