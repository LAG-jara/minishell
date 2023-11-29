/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_many.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:55:31 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/29 15:43:37 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// Adds the 'to_add' list nodes right before the 'pos' position.
void	lst_add_many(t_list **lst, t_list *pos, t_list *to_add)
{
	t_list	*prev;
	t_list	*next;

	if (!to_add)
		return ;
	if (!*lst)
	{
		*lst = to_add;
		return ;
	}
	if (!pos)
	{
		prev = lst_last(*lst);
		next = NULL;
	}
	else
	{
		prev = pos->pre;
		next = pos;
	}
	lst_link(prev, to_add);
	lst_link(lst_last(to_add), next);
	if (!prev)
		*lst = to_add;
}
