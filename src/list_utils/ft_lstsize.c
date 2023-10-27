/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:16:03 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/27 17:28:31 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xlist.h"

// Counts the number of nodes in a list.
size_t	ft_lstsize(t_lst *lst)
{
	size_t	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->nxt;
		size++;
	}
	return (size);
}
