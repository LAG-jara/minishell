/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:53:38 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/27 14:53:50 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xlist.h"

// Deletes and frees the given node and every successor of that node, using the
// function ’del’ and free(3). 
// Finally, the pointer to the list must be set to NULL.
void	ft_lstclear(t_lst **lst, void (*del)(void*))
{
	t_lst	*node;
	t_lst	*tmpnode;

	node = *lst;
	while (node)
	{
		tmpnode = node->nxt;
		ft_lstdelone(node, del);
		node = tmpnode;
	}
	*lst = NULL;
}
