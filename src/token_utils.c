/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:46:55 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/29 16:12:16 by glajara-         ###   ########.fr       */
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

// Given a string representing a token, returns its type.
int	token_type(char *str)
{
	if (!str)
		return (INVALID);
	if (ft_strncmp(str, ">", 2) == 0 || ft_strncmp(str, "<", 2) == 0
		|| ft_strncmp(str, "<<", 3) == 0 || ft_strncmp(str, ">>", 3) == 0)
		return (REDIR_OP);
	if (ft_strncmp(str, "|", 2) == 0)
		return (CTRL_OP);
	if (is_word(str))
		return (WORD);
	return (INVALID);
}

// Returns a token (with its type) wiven a string representing it.
t_token	token_create(char *str)
{
	t_token	token;

	token.val = ft_strdup(str);
	token.type = token_type(str);
	return (token);
}
