/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtoc_addc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:17:38 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/30 11:32:03 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Allocates and adds 'c' at the end of 'xtok' with the given flags.
t_xtoken	*xtok_addc(t_xtoken **xtok, char c, int x_flag, int q_flag)
{
	t_xchar xc;

	xc = xc_new(c, x_flag, q_flag);
	lst_add((*xtok)->val, lst_new(&xc, sizeof(t_xchar)));
}
