extern __errno_location

section .text
global ft_read

; ssize_t read(int fd, void *buf, size_t count);
; rdi holds the fd, rsi the buf and rdx the count
ft_read:
    mov rax, 0 ; Syscall code for read
    syscall

    cmp rax, 0 ; Check if the return is negative (error)
    jl error_handling ; Jump to error handling

    ret ; Return with the result in rax

error_handling:
    neg rax ; Negate rax to get positive error code
    mov rdi, rax ; Move error code to rdi (first argument for __errno_location)
    call __errno_location WRT ..plt ; Call __errno_location to get errno address
    mov [rax], rdi ; Store error code in errno
    mov rax, -1 ; Set the return value to -1 to indicate error
    ret
