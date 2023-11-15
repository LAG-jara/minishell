/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_xclst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:14:08 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/15 17:39:13 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Allocates and returns a list representing the 'str', with its given flags.
t_list	*str_to_xclst(const char *str, int x_flag, int q_flag)
{
	t_list	*lst;
	t_xchar	xc;

	lst = NULL;
	while (str && *str)
	{
		xc.c = *str;
		xc.x = x_flag;
		xc.q = q_flag;
		lst_add(&lst, lst_new(&xc, sizeof(xc)));
		++str;
	}
	return (lst);
}
