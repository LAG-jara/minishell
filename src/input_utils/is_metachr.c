/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_metachr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:56:50 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:24:09 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_utils.h"
#include "boolean.h"

// Returns TRUE if 'c' is the char <space>, <tab>, '<', '>' or '|', 
// returns FALSE otherwise.
int	is_metachr(int c)
{
	if (c == ' ' || c == '\t' || is_operatorchr(c))
		return (TRUE);
	return (FALSE);
}
