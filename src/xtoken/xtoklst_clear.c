/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtoklst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:24:13 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/02 11:24:15 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// static void del_xtoklst
// {

// }

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
	*xtoks = NULL;
}