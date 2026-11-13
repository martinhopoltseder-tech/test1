/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhopolts <mhopolts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:41:23 by mhopolts          #+#    #+#             */
/*   Updated: 2026/11/13 09:44:05 by mhopolts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	print_task(void *content)
{
	printf("%s\n", (char *)content);
}

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
	ft_lstiter(head, print_task);
	free(second);
	free(head);
	return (0);
}*/
