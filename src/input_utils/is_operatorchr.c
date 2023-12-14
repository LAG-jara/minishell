/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operatorchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:56:50 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:23:52 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_utils.h"
#include "boolean.h"

// Returns TRUE if 'c' is the char '<', '>' or '|', returns FALSE otherwise.
int	is_operatorchr(int c)
{
	if (is_redirectionchr(c) || c == '|')
		return (TRUE);
	return (FALSE);
}
