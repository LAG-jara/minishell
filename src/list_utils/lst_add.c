/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:37:52 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/27 18:59:00 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

// Adds the node 'new' at the end of the list.
void	lst_add(t_lst **lst, t_lst *new)
{
	t_lst	*node;

	node = lst_last(*lst);
	if (node)
		node->nxt = new;
	else
		*lst = new;
}
