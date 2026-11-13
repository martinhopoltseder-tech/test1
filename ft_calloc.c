/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhopolts <mhopolts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:27:40 by mhopolts          #+#    #+#             */
/*   Updated: 2026/10/25 22:30:18 by mhopolts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdint.h>

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	if (size != 0 && n > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(n * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, n * size);
	return (ptr);
}
/*
#include <stdint.h>
#include <stdlib.h>

int	main(void)
{
	int	*zahlen;

	zahlen = ft_calloc(5, sizeof(int));
	if (zahlen == NULL)
		return (1);
	free(zahlen);
	return (0);
}*/
