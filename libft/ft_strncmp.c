/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhopolts <mhopolts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:31:17 by mhopolts          #+#    #+#             */
/*   Updated: 2026/10/15 15:12:50 by mhopolts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/*
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "HALLO";
	s2 = "HALLE";
	printf("n = 3: %d\n", ft_strncmp(s1, s2, 3));
	printf("n = 5: %d\n", ft_strncmp(s1, s2, 5));
	printf("n = 0: %d\n", ft_strncmp(s1, s2, 0));
	return (0);
}*/
