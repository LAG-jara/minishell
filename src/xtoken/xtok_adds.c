/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtok_adds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:48:26 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/01 11:31:58 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Allocates and adds 'str' at the end of 'xtok' with the given flags.
void	xtok_adds(t_xtoken *xtok, char *str, int x_flag, int q_flag)
{
	t_xchar	xc;

	while (*str)
	{
		xc = xc_new(*str, x_flag, q_flag);
		lst_add(&xtok->val, lst_new(&xc, sizeof(xc)));
		++str;
	}
}
