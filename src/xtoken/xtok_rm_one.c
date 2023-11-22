/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtok_rm_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:23:08 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/31 13:26:32 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Removes and frees the given 'to_rm' node from the xtoken's value.
void	xtok_rm_one(t_xtoken *xtok, t_list *to_rm)
{
	t_list	*lst;

	lst = xtok->val;
	lst_rm_one(&lst, to_rm, free);
}
