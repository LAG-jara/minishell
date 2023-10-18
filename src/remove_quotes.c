/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:35:10 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/18 16:47:44 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_utils.h"
#include "token_utils.h"
#include "basic_utils.h"

// Gives how many qutes will need to be removed
int	quotes_to_remove(char *tok)
{
	int i;
	int to_remove;

	i = -1;
	to_remove = 0;
	while (tok[++i])
	{
		if (is_quotechr(tok[i]))
		{
			to_remove += 2;
			i += quote_skip(tok, i);
		}
	}
}



// Remove pairs of unclosed quotes form left 
char *remove_quotes_from_token(char *tok)
{
	int q2r;
	int dist;
	int i;

	i = ft_strlen(tok);
	q2r = quotes_to_remove(tok);
	if (!q2r)
		return (tok);
	new_tok = (char *)malloc(strlen(tok) - q2r + 1);
	if (!new_tok)
		exit (1);
	while (i--)
	{
		if (is_quotechr(tok[i]))
		{
			dist = quote_skip(tok);
			
		}
		else
			new_tok[i - q2r] = tok[i];
	}
}

// Removes all unquoted occurrences of the characters ‘'’ and ‘"’
// that did not result from expansion.
char	***remove_quotes(char ***commands)
{
	int i_comm;
	int i_tok;

	i_comm = -1;
	wihle(commands[++i_comm])
	{
		i_tok = -1;
		while(commands[i_comm][++i_tok])
			commands[i_comm][i_tok] = \
			remove_quotes_from_token(commands[i_comm][i_tok]);
	}
	return (commands);
}