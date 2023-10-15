/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:56:50 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/15 18:56:53 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"

// Returns TRUE if c is the char ' ' or '\t', returns FALSE otherwise.
int	is_blankchr(int c)
{
	if(c == ' ' || c == '\t')
		return (TRUE);
	return (FALSE);
}

// Returns TRUE if c is the char '<' or '>', returns FALSE otherwise.
int is_redirectionchr(int c)
{
	if(c == '<' || c == '>')
		return (TRUE);
	return (FALSE);
}

// Returns TRUE if c is the char '<', '>' or '|', returns FALSE otherwise.
int	is_operatorchr(int c)
{
	if(is_redirectionchr(c) || c == '|')
		return (TRUE);
	return (FALSE);
}

// Returns TRUE if c is the char ' ', '\t', '<', '>' or '|', 
// returns FALSE otherwise.
int	is_metachr(int c)
{
	if(c == ' ' || c == '\t' || is_operatorchr(c))
		return (TRUE);
	return (FALSE);
}

// Returns TRUE if c is the char '\'' or '"', returns FALSE otherwise.
int is_quotechr(int c)
{
	if(c == '\'' || c == '"')
		return (TRUE);
	return (FALSE);
}