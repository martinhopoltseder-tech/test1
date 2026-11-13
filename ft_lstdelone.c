/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhopolts <mhopolts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 09:30:14 by mhopolts          #+#    #+#             */
/*   Updated: 2026/11/13 09:33:02 by mhopolts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
/*#include "libft.h"
#include <stdlib.h>

int	main(void)
{
	char	*task;
	t_list	*node;

	task = ft_strdup("Code testen");
	if (task == NULL)
		return (1);
	node = ft_lstnew(task);
	if (node == NULL)
	{
		free(task);
		return (1);
	}
	ft_lstdelone(node, free);
	return (0);
}*/
