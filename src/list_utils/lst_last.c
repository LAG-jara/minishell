/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_last.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:38:47 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/27 18:59:00 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

// Returns the last node of the list.
t_lst	*lst_last(t_lst *lst)
{
	while (lst && lst->nxt)
		lst = lst->nxt;
	return (lst);
}
