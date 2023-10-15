/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:46:55 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/15 19:37:32 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_utils.h"
#include "input_utils.h"

// Given the current quote status and a character 'c', returns the new status.
int	update_quote_status(int curr_status, char c)
{
	if (curr_status == UNQUOTED)
	{
		if (c == '"')
			return (DQUOTED);
		if (c == '\'')
			return (QUOTED);
	}
	else if ((curr_status == QUOTED && c == '\'')
		|| (curr_status == DQUOTED && c == '"'))
		return (UNQUOTED);
	return (curr_status);
}

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
		if (quote_status == UNQUOTED && is_metachr(*str))
			return (FALSE);
		quote_status = update_quote_status(quote_status, *str);
		++str;
	}
	if (quote_status != UNQUOTED)
		return (FALSE);
	return (TRUE);
}

// Given a token, returns its token type.
int	token_type(char *token)
{
	if (!token)
		return (INVALID);
	if (ft_strncmp(token, ">", 2) == 0 || ft_strncmp(token, "<", 2) == 0
		|| ft_strncmp(token, "<<", 3) == 0 || ft_strncmp(token, ">>", 3) == 0)
		return (REDIR_OP);
	if (ft_strncmp(token, "|", 2) == 0)
		return (CTRL_OP);
	if (is_word(token))
		return (WORD);
	return (INVALID);
}
