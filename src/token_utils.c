/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:46:55 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/20 12:24:00 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_utils.h"

// Returns TRUE if 'str' is a valid word, FALSE otherwise.
static int	is_word(char *str)
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
