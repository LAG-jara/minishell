/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xc_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:07:09 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 16:20:26 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xchar.h"

// Creates and returns a new xchar with the 'c' char and the given flags.
t_xchar	xc_new(char c, int x_flag, int q_flag)
{
	t_xchar	xc;

	xc.c = c;
	xc.x = x_flag;
	xc.q = q_flag;
	return (xc);
}
