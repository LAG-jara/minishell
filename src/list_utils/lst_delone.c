/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_delone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:54:13 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/30 15:34:57 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

// Takes as a parameter a node and frees the memory of the node’s content using
// the function 'del' given as a parameter and free the node. The memory of
// 'nxt' and 'pre' must not be freed.
void	lst_delone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->val);
	free(lst);
}
