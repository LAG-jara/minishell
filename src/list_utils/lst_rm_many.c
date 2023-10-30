/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rm_many.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:22:49 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/30 16:18:48 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// Removes and frees 'n' list nodes starting from 'to_rm' right after 'pos',
// using the function 'del' and free(3). 
void	lst_rm_many(t_list **lst, t_list *to_rm, size_t n, void (*del)(void *))
{
	t_list	*prev;
	t_list	*next;

	if (*lst == to_rm)
		*lst = (*lst)->nxt;
	prev = to_rm->pre;
	next = to_rm;
	while (n-- > 0 && next)
	{
		to_rm = next;
		next = next->nxt;
		lst_delone(to_rm, del);
	}
	lst_link(prev, next);
}
