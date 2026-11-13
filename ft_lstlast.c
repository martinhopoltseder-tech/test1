/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhopolts <mhopolts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:17:40 by mhopolts          #+#    #+#             */
/*   Updated: 2026/11/13 09:19:13 by mhopolts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/*#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*head;
	t_list	*second;
	t_list	*last;

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
	last = ft_lstlast(head);
	printf("Letzter Knoten: %s\n", (char *)last->content);
	free(second);
	free(head);
	return (0);
}*/
