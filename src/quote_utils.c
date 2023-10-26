/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:23:40 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 17:24:07 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quote_utils.h"

// Given the current quote status and a character 'c', returns the new status.
int	upd_quote_stat(int curr_stat, char c)
{
	if (c == '"')
	{
		if (curr_stat == DQUOTED)
			return (UNQUOTED);
		if (curr_stat == UNQUOTED)
			return (DQUOTED);
	}
	else if (c == '\'')
	{
		if (curr_stat == QUOTED)
			return (UNQUOTED);
		if (curr_stat == UNQUOTED)
			return (QUOTED);
	}
	return (curr_stat);
}

// Get the string 'str' and the index 'i' of the current quote and 
// returns the distance to the next ocurrence of the same type of quote.
// If no quote is found returns the distance until the char before '\0'.
int	quote_skip(char *in, int i)
{
	char	target;
	int		dist;

	dist = 1;
	target = in[i];
	while (in[i + dist] && in[i + dist] != target)
		++dist;
	if (!in[i + dist])
		--dist;
	return (dist);
}
