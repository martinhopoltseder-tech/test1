#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *s);
const char	*gnl_find(const char *s, char c);
char	*gnl_join(const char *s1, const char *s2);
char	*gnl_line(const char *s);
char	*gnl_rest(const char *s);

#endif
