/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhopolts <mhopolts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:53:36 by mhopolts          #+#    #+#             */
/*   Updated: 2026/10/17 19:42:29 by mhopolts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	size_t	destlen;

	i = 0;
	while (i < destsize && dest[i] != '\0')
	{
		i++;
	}
	if (i == destsize)
		return (destsize + ft_strlen(src));
	destlen = i;
	j = 0;
	while (src[j] != '\0' && i < destsize -1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (destlen + ft_strlen(src));
}

/*	int	main(void)
{
	char	dest[15] = "Hallo";
	char	src[] = "Welt";
	size_t	result;

	result = ft_strlcat(dest, src, 15);
	printf("Ergebnis: %s\n", dest);
	printf("Rueckgabewert: %zu\n", result);
	return (0);
}*/
