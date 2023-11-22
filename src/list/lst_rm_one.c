/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rm_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:44:17 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/30 11:40:34 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// Removes and frees the given 'to_rm' node from the list, using the function 
// 'del' and free(3). 
void	lst_rm_one(t_list **lst, t_list *to_rm, void (*del)(void *))
{
	if (*lst == to_rm)
		*lst = (*lst)->nxt;
	lst_link(to_rm->pre, to_rm->nxt);
	lst_delone(to_rm, del);
}
