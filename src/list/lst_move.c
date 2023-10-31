/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:48:32 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/31 17:48:46 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// Returns the n-th node moving forward from 'n'.
// If 'n' is negative, moves backwards.
t_list	*lst_move(t_list *node, int n)
{
	while (n != 0)
	{
		if (!node)
			return (NULL);
		if (n > 0)
		{
			node = node->nxt;
			--n;
		}
		else
		{
			node = node->pre;
			++n;
		}
	}
	return (node);
}
