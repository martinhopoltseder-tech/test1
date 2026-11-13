/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhopolts <mhopolts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:06:55 by mhopolts          #+#    #+#             */
/*   Updated: 2026/11/13 09:08:02 by mhopolts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
/*#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*head;
	t_list	*new;

	head = ft_lstnew("Code testen");
	if (head == NULL)
		return (1);
	new = ft_lstnew("Libft ueben");
	if (new == NULL)
	{
		free(head);
		return (1);
	}
	ft_lstadd_front(&head, new);
	printf("1. %s\n", (char *)head->content);
	printf("2. %s\n", (char *)head->next->content);
	free(head->next);
	free(head);
	return (0);
}*/
