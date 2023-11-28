/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtok_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:40:26 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/28 19:17:53 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Given a xtoken list 'node' returns a pointer to its 'xtoken' value.
t_xtoken	*xtok_get(t_list *node)
{
	if (!node)
		return (NULL);
	return ((t_xtoken *)node->val);
}
