# Libasm

This project is an introduction to the Intel syntax Assembly language.

We have to create a library of basic functions from the libc, just like in libft !

Some guidelines to follow for this project:
- > You must write 64 bits ASM. Beware of the "calling convention".
- > You can’t do inline ASM, you must do ’.s’ files.
- > You must compile your assembly code with `nasm`.
- > You must use the Intel syntax, not the AT&T.

> [!WARNING]
> It is forbidden to use the compilation flag: `-no-pie`.

Now that some rules concerning how to code, the followings instructions concerns the library and the functions themselves:
- > The library must be called `libasm.a`.
- > You must submit a main that will test your functions and that will compile with your library to show that it’s functional.
- > You must check for errors during syscalls and properly set them when needed
- > Your code must set the variable errno properly.
- > For that, you are allowed to call the `extern ___error` or `errno_location`.

The function to recode are:
- [ft_strlen](#ft_strlen)
- [ft_strcpy](#ft_strcpy)
- [ft_strcmp](#ft_strcmp)
- [ft_strdup](#ft_strdup)
- [ft_write](#ft_write)
- [ft_read](#ft_read)

## ft_strlen

The reference to use: `man 3 strlen`

## ft_strcpy

The reference to use: `man 3 strcpy`

1. Buffer Overflow:

    My implementation (and the standard `strcpy`) does not check if `dest` is large enough to hold `src`, i.e. `strcpy` does not perform any bounds checking thus resulting in possible buffer overflow. This is a well-known security vulnerability of `strcpy`. If `dest` is smaller than `src`, it will write beyond the bounds of `dest`, causing undefined behavior, which can lead to crashes or security vulnerabilities.

2. Return Value:

    The function correctly returns a pointer to `dest` (in `rax`), which is the expected behavior according to the C standard. The return value is meant to allow function chaining and is not related to the content of the string.

    The function returns a pointer to `dest`. If `dest` is too small, the function will write beyond its bounds. Thus, when we print or examine the returned value, we are likely to see memory that was overwritten beyond `dest`'s allocated space.

    ```c
    char small_dest[5];
    char *result = strcpy(small_dest, "Hello, World!");

    printf("%s\n", result); // This might print "Hello, World!"
    ```

    In this case, `small_dest` is too small, but `strcpy` will write the entire string "Hello, World!" to memory starting at `small_dest`, overflowing its bounds. When printing `result`, we're seeing the overflowed data, not just the contents of `small_dest`.

## ft_strcmp

The reference to use: `man 3 strcmp`

## ft_strdup

The reference to use: `man 3 strdup` where we can call malloc

`ENOMEM = 12`

https://learn.microsoft.com/en-us/cpp/c-runtime-library/errno-constants?view=msvc-170

## ft_write

The reference to use: `man 2 write`

## ft_read

The reference to use: `man 2 read`

## extern / errno_location

`call __errno_location WRT ..plt`:

1. `call`: x86 assembly instruction that calls a function. It pushes the return address onto the stack and jumps to the specified function.
2. `__errno_location`: a function provided by the C standard library (libc) that returns a pointer to the current thread's errno variable. In multi-threaded programs, each thread has its own errno value.
3. `WRT ..plt`: This is the crucial part for understanding how the call works in the context of shared libraries and position-independent code (PIC).
    - `WRT` stands for "with respect to" and is used to specify a relocation type.
    - `..plt` refers to the Procedure Linkage Table, which is a mechanism used for calling external functions in shared libraries.
4. Purpose of PLT:
    - In position-independent code, the exact addresses of external functions are not known at compile time.
    - The PLT provides a level of indirection that allows the dynamic linker to resolve these addresses at runtime.
5. How it works:
    - When you call a function with `WRT ..plt`, it actually calls a stub in the PLT.
    - The first time the function is called, this stub transfers control to the dynamic linker, which resolves the actual address of the function.
    - Subsequent calls go directly to the resolved address, bypassing the dynamic linker.
6. Advantages:
    - This mechanism allows for lazy binding, where function addresses are only resolved when they're first called, improving startup time.
    - It enables position-independent code, which is crucial for shared libraries and security features like ASLR (Address Space Layout Randomization).
7. In the context of `__errno_location`:
    - By using `WRT ..plt`, your assembly code can call this libc function without knowing its exact address in memory.
    - This makes your code more flexible and compatible with different libc versions or system configurations.
8. After the call:
    - `__errno_location` returns a pointer (in `rax`) to the errno variable for the current thread.
    - You can then use this pointer to read or write the errno value.

In summary, `call __errno_location WRT ..plt` is a way to call the `__errno_location` function from assembly code in a manner that's compatible with shared libraries and position-independent code. It uses the PLT mechanism to allow the dynamic linker to resolve the actual address of the function at runtime.

## `-no-pie`

The `-no-pie` flag instructs GCC to generate a non-position-independent executable. Position Independent Executables (PIE) are a security feature that allows the entire program to be loaded at a random memory address each time it's run, making certain types of attacks more difficult. However, PIE can have a small performance cost.

Using `-no-pie`:

1. Disables PIE, potentially improving performance slightly
2. May be necessary for certain low-level or embedded applications
3. Reduces security by making the program's memory layout more predictable

It's generally recommended to use PIE (i.e., omit `-no-pie`) for better security unless you have a specific reason to disable it.

https://stackoverflow.com/questions/47778099/what-is-no-pie-used-for

https://www.redhat.com/en/blog/position-independent-executables-pie

## sources

https://cs.lmu.edu/~ray/notes/nasmtutorial/
