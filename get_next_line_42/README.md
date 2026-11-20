*This activity has been created as part of the 42 curriculum by mhopolts.*

# Get Next Line

## Description

`get_next_line(int fd)` returns the next line from a file descriptor. Each
returned string is allocated and must be freed by its caller. A line includes
its newline character, when present. End of file or a read/allocation error
returns `NULL`.

## Instructions

Compile with a chosen buffer size:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
  get_next_line.c get_next_line_utils.c test_main.c -o test
./test test.txt
```

`test_main.c` and `test.txt` are local tests, not submission files. The required
submission is `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`,
and this `README.md` in the repository root.

## Algorithm and rationale

A function-local static pointer (`stash`) keeps unread data across calls.
`gnl_read` reads up to `BUFFER_SIZE` bytes at a time until a newline occurs
or EOF is reached. A dynamically allocated buffer is used rather than a huge
stack array. `gnl_join` appends read data to the retained text. `gnl_line`
extracts one complete line and `gnl_rest` allocates the unconsumed suffix.
The previous stored text is freed, then the suffix becomes the next `stash`.
On errors, allocated memory is released and `NULL` is returned. This strategy
avoids reading the rest of a file after the next line is already available.
Only one file descriptor's unread data is stored, as in the mandatory part.

## Resources

- 42 Get Next Line subject, version 1.3.
- `man 2 read`, `man 3 malloc`, `man 3 free`.
- The 42 Norm, version 4.1.

AI was used to discuss the assignment, draft an implementation, and suggest
compile-and-run tests. The student should independently review, understand,
and verify the work before submission.
