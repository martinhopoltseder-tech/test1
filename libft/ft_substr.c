/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhopolts <mhopolts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:08:55 by mhopolts          #+#    #+#             */
/*   Updated: 2026/10/25 22:53:17 by mhopolts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s + start, len + 1);
	return (copy);
}
/*#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    char *str = "Hello World!";
    char *result;

    result = ft_substr(str, 6, 5);
    printf("Result: %s\n", result);

    free(result);
    return (0);
}*/
