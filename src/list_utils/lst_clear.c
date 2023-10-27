/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:53:38 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/27 18:57:55 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

// Deletes and frees the given node and every successor of that node, using the
// function 'del' and free(3). 
// Finally, the pointer to the list must be set to NULL.
void	lst_clear(t_lst **lst, void (*del)(void *))
{
	t_lst	*node;
	t_lst	*nxt_node;

	node = *lst;
	while (node)
	{
		nxt_node = node->nxt;
		lst_delone(node, del);
		node = nxt_node;
	}
	*lst = NULL;
}