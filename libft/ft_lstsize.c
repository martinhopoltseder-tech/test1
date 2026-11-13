/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhopolts <mhopolts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:08:56 by mhopolts          #+#    #+#             */
/*   Updated: 2026/11/13 09:09:33 by mhopolts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
/*#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*head;
	t_list	*second;

	head = ft_lstnew("Libft ueben");
	if (head == NULL)
		return (1);
	second = ft_lstnew("Code testen");
	if (second == NULL)
	{
		free(head);
		return (1);
	}
	head->next = second;
	printf("Anzahl: %d\n", ft_lstsize(head));
	free(second);
	free(head);
	return (0);
}*/
