/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhopolts <mhopolts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:32:15 by mhopolts          #+#    #+#             */
/*   Updated: 2026/11/13 10:32:54 by mhopolts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*node;
	void	*content;

	if (f == NULL || del == NULL)
		return (NULL);
	result = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (node == NULL)
		{
			del(content);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, node);
		lst = lst->next;
	}
	return (result);
}
/*#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	*copy_task(void *content)
{
	return (ft_strdup((char *)content));
}

int	main(void)
{
	t_list	*original;
	t_list	*copy;

	original = ft_lstnew("Code testen");
	if (original == NULL)
		return (1);
	copy = ft_lstmap(original, copy_task, free);
	free(original);
	if (copy == NULL)
		return (1);
	if (copy->content != NULL)
		printf("%s\n", (char *)copy->content);
	ft_lstclear(&copy, free);
	return (0);
}*/
