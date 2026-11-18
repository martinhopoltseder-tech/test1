*This activity has been created as part of the 42 curriculum by mhopolts.*

# ft_printf

## Description

This project implements a subset of the C library's printf function. It produces
`libftprintf.a`, a static library exposing the following function.

```c
int ft_printf(const char *format, ...);
```

The function writes to standard output and returns the number of bytes written.
It returns `-1` when an output operation fails. Supported conversions are listed
below.

| Conversion | Output |
| --- | --- |
| `%c` | One character |
| `%s` | A null-terminated string |
| `%p` | A pointer in hexadecimal |
| `%d`, `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` | An unsigned hexadecimal integer using lowercase letters |
| `%X` | An unsigned hexadecimal integer using uppercase letters |
| `%%` | A literal percent sign, without consuming an argument |

This implementation prints `(null)` for a null string and `(nil)` for a null
pointer. Non-null pointers use the `0x` prefix and lowercase hexadecimal digits.
A null format pointer, unsupported conversion, or trailing `%` returns `-1`.
The project implements the mandatory conversions without flags, field widths,
precision, or buffered output. It does not depend on Libft.

## Instructions

A C compiler (`cc`), Make, and `ar` are required. Put these files in the repository
root using their original names, without upload suffixes such as `(3)`.

- `ft_printf.c`
- `ft_printf_chars.c`
- `ft_printf_numbers.c`
- `ft_printf.h`
- `Makefile`
- `README.md`

| Command | Action |
| --- | --- |
| `make` | Builds `libftprintf.a` with `-Wall -Wextra -Werror`. |
| `make clean` | Removes object files. |
| `make fclean` | Also removes the library. |
| `make re` | Cleans and rebuilds the library. |

Before building the supplied version, add `# include <stddef.h>` to
`ft_printf.h` so that `NULL` is defined in `ft_printf.c`.

For a local test, create a separate `main.c` in the project directory.

```c
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	count;

	count = ft_printf("Hello %s! %d %x %%\n", "42", -42, 255u);
	printf("Return value: %d\n", count);
	return (0);
}
```

Compile and run the test from the project directory.

```sh
make
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

Expected output follows.

```text
Hello 42! -42 ff %
Return value: 19
```

Other useful comparisons with the original `printf` include empty strings, zero,
negative integers, integer limits, hexadecimal case, and null pointers. A `%c`
conversion containing the null character still writes one byte and counts it.

## Algorithm and data structures

The implementation scans the format string from left to right using an integer
index. Ordinary characters are written immediately. At a `%`, the next character
selects a conversion, and the index skips both characters after processing it.
A running total accumulates the bytes reported by the output helpers. On an
error, scanning stops, `va_end` runs, and the function returns `-1`.

A `va_list` holds the state used to access the additional arguments. `va_start`
initializes it, each conversion consumes the appropriate argument with `va_arg`,
and `va_end` completes its use. Helpers receive its address so they update the
same state. Character arguments are read as `int` because of argument promotions.

The dispatcher is split between `emit_format` and `emit_format_more` to keep the
conversion cases manageable. `emit_one` processes one ordinary character or one
conversion. `emit_char` checks `write` and `emit_string` visits each byte up to
the terminator.

`emit_nbr_base` uses recursion to output digits in their natural order. It first
prints the quotient, then indexes the supplied digit string using the remainder.
The digit strings select base 10 or base 16 and the hexadecimal letter case.
This shares one algorithm between unsigned integers, signed magnitudes, and
pointer addresses. Zero reaches the final digit output directly.

`emit_signed` converts its input to `long long` before negating a negative value,
which handles the minimum 32-bit integer on the target platform. `emit_pointer`
uses `uintptr_t` from `<stdint.h>` to convert a pointer to an integer before
printing it in hexadecimal.

The data consists of the format string, the argument state, scalar counters,
and constant digit strings. No heap allocation is used. The format scan is
linear in its length plus the number of output bytes. Numeric recursion uses
stack space proportional to the number of digits.

## Resources

- The 42 ft_printf subject, version 1.1, for mandatory conversions and submission
  requirements.
- The 42 Norm for C source formatting.
- System manual pages, including `man 3 printf`, `man 3 stdarg`, `man 2 write`,
  and `man 1 ar`.
- `<stdarg.h>` documentation for `va_list`, `va_start`, `va_arg`, `va_end`,
  and `va_copy`.

### AI usage

AI assistance was used to discuss the task and propose a program structure.
