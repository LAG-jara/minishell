/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:56:50 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/19 15:25:42 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"

// Returns TRUE if 'c' is the char <space> or <tab>, returns FALSE otherwise.
int	is_blankchr(int c)
{
	if (c == ' ' || c == '\t')
		return (TRUE);
	return (FALSE);
}

// Returns TRUE if 'c' is the char '<' or '>', returns FALSE otherwise.
int	is_redirectionchr(int c)
{
	if (c == '<' || c == '>')
		return (TRUE);
	return (FALSE);
}

// Returns TRUE if 'c' is the char '<', '>' or '|', returns FALSE otherwise.
int	is_operatorchr(int c)
{
	if (is_redirectionchr(c) || c == '|')
		return (TRUE);
	return (FALSE);
}

// Returns TRUE if 'c' is the char <space>, <tab>, '<', '>' or '|', 
// returns FALSE otherwise.
int	is_metachr(int c)
{
	if (c == ' ' || c == '\t' || is_operatorchr(c))
		return (TRUE);
	return (FALSE);
}

// Returns TRUE if 'c' is the char ' or ", returns FALSE otherwise.
int	is_quotechr(int c)
{
	if (c == '\'' || c == '"')
		return (TRUE);
	return (FALSE);
}
