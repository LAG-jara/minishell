/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:37:52 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/30 11:36:28 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

// Adds the node 'new' at the end of the list.
void	lst_add(t_list **lst, t_list *new)
{
	t_list	*node;

	node = lst_last(*lst);
	if (node)
		node->nxt = new;
	else
		*lst = new;
}
