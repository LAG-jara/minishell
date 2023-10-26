/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:46:55 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 18:03:33 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token_utils.h"

// Returns TRUE if 'str' is a valid word, FALSE otherwise.
static int	is_word(char *str)
{
	int	q_stat;

	q_stat = UNQUOTED;
	while (*str)
	{
		if (q_stat == UNQUOTED && is_metachr(*str))
			return (FALSE);
		q_stat = quote_stat(q_stat, *str);
		++str;
	}
	if (q_stat != UNQUOTED)
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
