/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:16:03 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/27 18:58:25 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

// Counts and returns the amount of nodes in a list.
size_t	lst_size(t_lst *lst)
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
