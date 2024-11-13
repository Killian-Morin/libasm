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

## ft_strcmp

The reference to use: `man 3 strcmp`

## ft_strdup

The reference to use: `man 3 strdup` where we can call malloc

## ft_write

The reference to use: `man 2 write`

## ft_read

The reference to use: `man 2 read`
