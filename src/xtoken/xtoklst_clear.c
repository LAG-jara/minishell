/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtoklst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:24:13 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/14 16:05:09 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Clears the list of xtokens.
void	xtoklst_clear(t_list **xtoks)
{
	t_list	*node;
	t_list	*nxt_node;

	node = *xtoks;
	while (node)
	{
		nxt_node = node->nxt;
		lst_clear(node->val, free);
		node = nxt_node;
	}
	lst_clear(xtoks, free);
}
