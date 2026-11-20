#include "get_next_line.h"

static char	*gnl_free(char *stash)
{
	free(stash);
	return (NULL);
}

static char	*gnl_read(int fd, char *stash)
{
	char	*buffer;
	char	*joined;
	ssize_t	bytes;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (gnl_free(stash));
	bytes = 1;
	while (gnl_find(stash, '\n') == NULL && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		joined = gnl_join(stash, buffer);
		free(stash);
		stash = joined;
		if (stash == NULL)
			break ;
	}
	free(buffer);
	if (bytes < 0)
		return (gnl_free(stash));
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*rest;
	const char	*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = gnl_read(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = gnl_line(stash);
	newline = gnl_find(stash, '\n');
	rest = gnl_rest(stash);
	if (line == NULL || (newline != NULL && newline[1] != '\0'
			&& rest == NULL))
	{
		free(line);
		free(stash);
		stash = NULL;
		return (NULL);
	}
	free(stash);
	stash = rest;
	return (line);
}
