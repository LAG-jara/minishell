/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:44:17 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/27 18:58:53 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

// Removes and frees the given 'to_rm' node from the list, using the function 
// 'del' and  free(3). 
void	lst_rm(t_lst **lst, t_lst *to_rm, void (*del)(void *))
{
	t_lst	*node;

	node = *lst;
	while (node && node != to_rm)
		node = node->nxt;
	if (node == to_rm)
	{
		lst_link(node->pre, node->nxt);
		lst_delone(node, del);
	}
	*lst = NULL;
}
