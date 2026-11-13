/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhopolts <mhopolts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:20:30 by mhopolts          #+#    #+#             */
/*   Updated: 2026/11/05 11:12:52 by mhopolts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (i + j < len && little[j] != '\0'
			&& big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	const char	*big = "Hallo Welt";
	const char	*little = "Welt";
	char		*result;

	result = ft_strnstr(big, little, 10);
	if (result != NULL)
		printf("Gefunden: %s\n", result);
	else
		printf("Nicht gefunden\n");
	return (0);
}*/
