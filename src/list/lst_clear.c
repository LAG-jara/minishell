/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:53:38 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/12 17:43:05 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// Deletes and frees the given node and every successor of that node, using the
// function 'del' and free(3). 
// Finally, the pointer to the list must be set to NULL.
void	lst_clear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*nxt_node;

	node = *lst;
	while (node)
	{
		nxt_node = node->nxt;
		lst_delone(node, del);
		node = nxt_node;
	}
	*lst = NULL;
}
