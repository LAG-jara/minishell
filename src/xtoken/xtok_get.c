/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtok_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:40:26 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/03 18:45:17 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Given a xtoken list 'node' returns its 'xtoken' value
t_xtoken	xtok_get(t_list *node)
{
	t_xtoken	xtok;

	if (node)
		xtok = *(t_xtoken *)node->val;
	else
	{
		xtok.val = NULL;
		xtok.type = INVALID;
	}
	return (xtok);
}
