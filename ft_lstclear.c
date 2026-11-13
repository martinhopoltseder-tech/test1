/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhopolts <mhopolts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:33:25 by mhopolts          #+#    #+#             */
/*   Updated: 2026/11/13 09:34:40 by mhopolts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}
/*#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*task;
	t_list	*head;

	task = ft_strdup("Code testen");
	if (task == NULL)
		return (1);
	head = ft_lstnew(task);
	if (head == NULL)
	{
		free(task);
		return (1);
	}
	ft_lstclear(&head, free);
	if (head == NULL)
		printf("Liste ist leer.\n");
	return (0);
}*/
