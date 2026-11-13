/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhopolts <mhopolts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 08:58:25 by mhopolts          #+#    #+#             */
/*   Updated: 2026/11/13 12:56:13 by mhopolts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
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
	printf("1. %s\n", (char *)head->content);
	printf("2. %s\n", (char *)head->next->content);
	free(second);
	free(head);
	return (0);
}*/
