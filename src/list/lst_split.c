/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:17:46 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/01 13:43:36 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// Splits the list at 'node', unlinking it from previous nodes (if any).
void	lst_split(t_list *node)
{
	t_list	*prev;

	if (!node)
		return ;
	prev = node->pre;
	if (prev)
		prev->nxt = NULL;
	node->pre = NULL;
}
