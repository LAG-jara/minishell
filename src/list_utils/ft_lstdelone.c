/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:54:13 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/27 14:54:24 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xlist.h"

// Takes as a parameter a node and frees the memory of the node’s content using
// the function ’del’ given as a parameter and free the node. The memory of
// ’next’ must not be freed.
void	ft_lstdelone(t_lst *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->val);
	free(lst);
}
