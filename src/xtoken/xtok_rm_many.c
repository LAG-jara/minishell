/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtok_rm_many.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:56:38 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/31 18:01:04 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Removes and frees 'n' nodes from the xtoken's value, starting from 'to_rm'.
void	xtok_rm_many(t_xtoken *xtok, t_list *to_rm, size_t n)
{
	t_list	*lst;

	lst = xtok->val;
	lst_rm_many(&lst, to_rm, n, free);
}
