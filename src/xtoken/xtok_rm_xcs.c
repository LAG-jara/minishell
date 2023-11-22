/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtok_rm_xcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:17:39 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/31 15:12:51 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Removes all ocurrences of 'to_rm' from the given xtoken.
void	xtok_rm_xcs(t_xtoken *xtok, t_xchar *to_rm)
{
	t_xchar	xc;
	t_list	*curr_node;
	t_list	*next_node;

	curr_node = xtok->val;
	while (curr_node)
	{
		xc = *(t_xchar *)curr_node->val;
		next_node = curr_node->nxt;
		if (xc.c == to_rm->c && xc.q == to_rm->q && xc.x == to_rm->x)
		{
			if (xtok->val == curr_node)
				xtok->val = next_node;
			xtok_rm_one(xtok, curr_node);
		}
		curr_node = next_node;
	}
}
