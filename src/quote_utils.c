/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:23:40 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:16:26 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quote_utils.h"

// Given the current quote status and a character 'c', updates its value and
// returns the status for 'c'.
int	quote_stat(int *curr_stat, char c)
{
	if (c == '"')
	{
		if (*curr_stat == DQUOTED)
			*curr_stat = UNQUOTED;
		else if (*curr_stat == UNQUOTED)
		{
			*curr_stat = DQUOTED;
			return (UNQUOTED);
		}
	}
	else if (c == '\'')
	{
		if (*curr_stat == QUOTED)
			*curr_stat = UNQUOTED;
		else if (*curr_stat == UNQUOTED)
		{
			*curr_stat = QUOTED;
			return (UNQUOTED);
		}
	}
	return (*curr_stat);
}
