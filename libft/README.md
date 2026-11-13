*This activity has been created as part of the 42 curriculum by mhopolts.*

# Libft

## Description

Libft is a static C library built as part of the 42 Common Core. The project
reimplements common C library functions and adds reusable helpers for later
projects. The public declarations are in `libft.h`, and the build produces
`libft.a` in the repository root.

| Area | What the library provides |
| --- | --- |
| Characters | Character classification and case conversion, such as `ft_isalpha` and `ft_toupper`. |
| Memory | Filling, copying, moving, searching, and comparing byte ranges, plus zero-initialized allocation with `ft_calloc`. |
| Strings | Measuring, copying, comparing, and searching strings, plus helpers to extract, join, trim, split, and transform them. |
| Conversion and output | Converting between integers and strings with `ft_atoi` and `ft_itoa`, and writing characters, strings, and integers to file descriptors. |

Functions that return newly allocated strings, such as `ft_strdup` and
`ft_itoa`, leave ownership of those strings with the caller. Free each
returned string when it is no longer needed. For `ft_split`, free each
substring and then the array of pointers.

## Instructions

The repository root contains `Makefile`, `libft.h`, `README.md`, and the
`ft_*.c` source files, including the linked list sources (`ft_lst*.c`).

Run the following commands from that directory. GNU Make compiles the source
files with `cc -Wall -Wextra -Werror` and archives the object files with
`ar rcs`.

| Command | Result |
| --- | --- |
| `make` or `make all` | Builds `libft.a` from the sources listed in the Makefile. |
| `make clean` | Removes the object files. |
| `make fclean` | Also removes `libft.a`. |
| `make re` | Runs `fclean` and rebuilds `libft.a`. |

To use the library, include `libft.h` and link your program against
`libft.a`. For a local test, create a separate `main.c` in the project
directory with this example.

```c
#include "libft.h"

int	main(void)
{
	ft_putendl_fd("Hello Libft", 1);
	return (0);
}
```

```sh
make
cc -Wall -Wextra -Werror main.c libft.a -o test
./test
```

The expected output is `Hello Libft`. The example `main.c` and its `test`
executable are for local testing.

## Resources

- The 42 Libft subject for the project requirements.
- The 42 Norm for C coding style.
- Linux manual pages for library functions and system calls, including
  `man 3 malloc`, `man 3 strdup`, `man 2 write`, and `man 3type size_t`.

### AI usage
AI was used (as Tutor) to explain C concepts and walk through example implementations
and test programs and troubleshoot written codes. It also helped draft this README.
