/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_removal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:35:10 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/15 18:35:14 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_utils.h"

// Remove pairs of unclosed quotes form left 
char *remove_quotes_from_token(char *tok)
{
	int i;
	int to_remove;

	i = -1;
	to_remove = 0;
	if (is_operatorchr(*tok))
		return (tok);
	while (tok[++i])
	{
		if (is_quotechrtok(tok[i]))
		{
			to_remove += 2;
			qu
		}
	}
}

// All unquoted occurrences of the characters `'’ and `"’ that did not result
// from one of the above expansions are removed. 
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