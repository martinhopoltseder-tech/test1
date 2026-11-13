/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhopolts <mhopolts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:23:06 by mhopolts          #+#    #+#             */
/*   Updated: 2026/11/13 09:26:07 by mhopolts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*head;
	t_list	*new;

	head = ft_lstnew("Libft ueben");
	if (head == NULL)
		return (1);
	new = ft_lstnew("Code testen");
	if (new == NULL)
	{
		free(head);
		return (1);
	}
	ft_lstadd_back(&head, new);
	printf("1. %s\n", (char *)head->content);
	printf("2. %s\n", (char *)head->next->content);
	free(new);
	free(head);
	return (0);
}*/
