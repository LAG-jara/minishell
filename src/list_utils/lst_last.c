/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:38:47 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/30 11:36:28 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

// Returns the last node of the list.
t_list	*lst_last(t_list *lst)
{
	while (lst && lst->nxt)
		lst = lst->nxt;
	return (lst);
}
