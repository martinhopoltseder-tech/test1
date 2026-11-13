/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhopolts <mhopolts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:23:52 by mhopolts          #+#    #+#             */
/*   Updated: 2026/11/02 14:48:48 by mhopolts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	wc;
	int		in_word;

	i = 0;
	wc = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			in_word = 0;
		else if (in_word == 0)
		{
			wc++;
			in_word = 1;
		}
		i++;
	}
	return (wc);
}

static void	free_split(char **result, size_t ray)
{
	while (ray > 0)
	{
		ray--;
		free(result[ray]);
	}
	free(result);
}

static int	fill_words(char **result, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	ray;

	i = 0;
	ray = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		result[ray] = ft_substr(s, start, i - start);
		if (result[ray] == NULL)
		{
			free_split(result, ray);
			return (0);
		}
		ray++;
	}
	result[ray] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	wc;

	if (s == NULL)
		return (NULL);
	wc = count_words(s, c);
	result = malloc(sizeof(char *) * (wc + 1));
	if (result == NULL)
		return (NULL);
	if (fill_words(result, s, c) == 0)
		return (NULL);
	return (result);
}
/*
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char    **result;
    int     i;

    result = ft_split("Hallo Welt das ist ein Test", ' ');
    if (result == NULL)
        return (1);

    i = 0;
    while (result[i] != NULL)
    {
        printf("result[%d] = %s\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);
    return (0);
}
*/
