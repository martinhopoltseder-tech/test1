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
| Linked lists (bonus) | Creating and inserting nodes, counting and finding nodes, deleting and clearing lists, and iterating or mapping over their contents. |

Functions that return newly allocated strings, such as `ft_strdup` and
`ft_itoa`, leave ownership of those strings with the caller. Free each
returned string when it is no longer needed. For `ft_split`, free each
substring and then the array of pointers.

## Instructions

Run the following commands from the repository root. The build uses `cc`
with `-Wall -Wextra -Werror`, GNU Make, and `ar`.

| Command | Result |
| --- | --- |
| `make` | Builds the mandatory functions into `libft.a`. |
| `make bonus` | Builds the library with the linked list functions. |
| `make clean` | Removes the object files and the bonus marker. |
| `make fclean` | Also removes `libft.a`. |
| `make re` | Cleans and rebuilds the mandatory part. |

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

The expected output is `Hello Libft`. Run `make bonus` before linking a
program that uses the linked list functions.

## Resources

- The 42 Libft subject for the project requirements.
- The 42 Norm for C coding style.
- Linux manual pages for library functions and system calls, including
  `man 3 malloc`, `man 3 strdup`, `man 2 write`, and `man 3type size_t`.

### AI usage

AI was used (as Tutor) to explain C concepts and walk through example implementations
and test programs and troubleshoot written codes. It also helped draft this README.
