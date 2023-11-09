/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_first.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:50:38 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/09 18:51:45 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

// Returns the first node of the list.
t_list	*lst_first(t_list *lst)
{
	while (lst && lst->pre)
		lst = lst->pre;
	return (lst);
}
