#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
		i++;
	return (i);
}

const char	*gnl_find(const char *s, char c)
{
	int	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*gnl_join(const char *s1, const char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*gnl_line(const char *s)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] != '\0' && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*gnl_rest(const char *s)
{
	const char	*newline;
	char	*rest;
	size_t	i;

	newline = gnl_find(s, '\n');
	if (newline == NULL || newline[1] == '\0')
		return (NULL);
	rest = malloc(gnl_strlen(newline + 1) + 1);
	if (rest == NULL)
		return (NULL);
	i = 0;
	while (newline[i + 1] != '\0')
	{
		rest[i] = newline[i + 1];
		i++;
	}
	rest[i] = '\0';
	return (rest);
}
