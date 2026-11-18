*This activity has been created as part of the 42 curriculum by mhopolts.*

# ft_printf

## Description

A small C library that reproduces the mandatory `printf` conversions:
`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.
It returns the number of bytes written, or -1 on a write error.
The resulting static library is `libftprintf.a`.

## Instructions

Run `make` to build `libftprintf.a`, `make clean` to remove object
files, `make fclean` to remove the library too, and `make re` to rebuild.
Link a separate test program with:

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

## Algorithm and data structures

The format string is scanned sequentially. Literal characters are written
with `write`, and each supported conversion consumes its corresponding
argument using `va_arg`. A `va_list` maintains the variadic argument state.
Integer formatting uses recursive division by the chosen base to print
most significant digits before least significant digits. Signed numbers
use `long` so the magnitude of a 32-bit `INT_MIN` is representable.
Pointers are written with the `0x` prefix and lowercase hexadecimal digits;
on the glibc/Linux system, a null pointer is displayed as `(nil)`.
No heap allocations or output buffers are required, so no dynamic data
structure is necessary. Output counts accumulate the number of bytes written.

## Resources

- The 42 `ft_printf` subject (version 1.1).
- `man 3 printf`, `man 3 stdarg`, `man 2 write`.
- The 42 Norm, version 4.1.

AI assistance was used to discuss the task and propose a program structure.
