/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:37:52 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/30 16:18:48 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// Adds the node 'new' at the end of the list.
void	lst_add(t_list **lst, t_list *new)
{
	t_list	*node;

	node = lst_last(*lst);
	if (node)
		lst_link(node, new);
	else
		*lst = new;
}
