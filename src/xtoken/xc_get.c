/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xc_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:02:45 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/01 10:10:39 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Given a xchar list 'node' returns its 'xchar' value
t_xchar	xc_get(t_list *node)
{
	t_xchar	xc;

	xc = *(t_xchar *)node->val;
	return (xc);
}
