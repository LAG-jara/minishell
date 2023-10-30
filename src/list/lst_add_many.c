/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_many.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:55:31 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/30 16:18:48 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// Adds the 'to_add' list nodes right after the 'pos' position.
void	lst_add_many(t_list **lst, t_list *pos, t_list *to_add)
{
	t_list	*prev;
	t_list	*next;

	if (!*lst)
	{
		*lst = to_add;
		return ;
	}
	if (!pos)
		return;
	prev = pos;
	next = pos->nxt;
	lst_link(prev, to_add);
	lst_link(lst_last(to_add), next);
}
