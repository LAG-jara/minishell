/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:46:55 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/15 19:10:58 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_utils.h"
#include "input_utils.h"

// Get the string of the input(in) and the index(i) of the current quote and 
// returns the distance(dist) to the next ocurrence of the same type of quote.
// If no quote is found returns the distance until the char before '\0'.
int quote_skip(char *in, int i)
{
	char	target;
	int 	dist;

	dist = 1;
	target = in[i];
	while (in[i + dist] && in[i + dist] != target)
		++dist;
	if(!in[i + dist])
		--dist;
	return(dist);
}

// Returns TRUE if 'str' is a valid word, FALSE otherwise.
int	is_word(char *str)
{
	int	quote_status;

	quote_status = UNQUOTED;
	while (*str)
	{
		if (quote_status == UNQUOTED)
		{
			if (is_metachr(*str))
				return (FALSE);
		}
		else
		{
			if (quote_status == QUOTED && *str == '\''
				|| quote_status == DQUOTED && *str == '"')
				quote_status = UNQUOTED;
		}
		++str;
	}
	if (quote_status == QUOTED)
		return (TRUE);
	return (FALSE);
}

// Given a token, returns its token type.
t_token_type	token_type(char *token)
{
	if (!token)
		return (INVALID);
	if (ft_strncmp(token, ">", 2) == 0 || ft_strncmp(token, "<", 2) == 0
		|| ft_strncmp(token, "<<", 3) == 0 || ft_strncmp(token, ">>", 3) == 0)
		return (REDIR_OP);
	if (ft_strncmp(token, "|", 2))
		return (CTRL_OP);
	if (is_word(token))
		return (WORD);
	return (INVALID);
}
