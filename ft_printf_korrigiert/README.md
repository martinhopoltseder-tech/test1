*This activity has been created as part of the 42 curriculum by <login>.*

# ft_printf

## Description
A small implementation of `printf` supporting `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X` and `%%`. It writes characters directly to standard output without a printf-style output buffer. The return value is the number of characters written, or `-1` if writing or format dispatch fails.

## Design and algorithm
`ft_printf` loops through the format string using an index `i` and explicit increments. `emit_one` checks each character and delegates conversions to `emit_format`. Ordinary characters go to `emit_char`; after `%`, the conversion is dispatched by `emit_format` (and its short auxiliary branch `emit_format_more`, required to keep the dispatch within the Norm line limit). There is no `emit_next` function.

`emit_string` prints characters in sequence; `emit_signed` handles the sign of negative decimal integers; `emit_nbr_base` recursively prints digits for base 10 or base 16 depending on its digit alphabet; `emit_pointer` adds the `0x` prefix and prints a hexadecimal address. Null strings display `(null)` and null pointers `(nil)` in this implementation.

The main recursion algorithm for a number n in base b is: if n >= b, first print n / b, then print the digit at index n % b. This outputs digits from most significant to least significant. Every output helper returns its character count or `-1`, so errors propagate to `ft_printf`.

## Instructions
Run `make` to build `libftprintf.a`, `make clean` to remove object files, `make fclean` to remove objects and archive, and `make re` to rebuild. Compile your own test C file with `cc -Wall -Wextra -Werror test.c libftprintf.a`.

Before submitting, replace `<login>` and the placeholder identity in the 42 headers with your own login and student email. Confirm behavior against your campus libc and review requirements.

## Resources and AI use
Resources: `man 3 printf`, `man 3 stdarg`, `man 2 write`, 42 Printf subject and Norm 4.1. AI assistance was used for a suggested function architecture, an illustrative implementation, and compilation/smoke tests. Review and adapt this code yourself before submitting; update this section to accurately reflect your actual workflow.
