/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:46:55 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:01:55 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "basic_utils.h"
#include "input_utils.h"
#include "quote_utils.h"
#include "list.h"

// Given a string representing a token, returns its type.
int	tok_type(const char *str)
{
	if (!str)
		return (INVALID);
	if (ft_strncmp(str, ">", 2) == 0 || ft_strncmp(str, "<", 2) == 0
		|| ft_strncmp(str, "<<", 3) == 0 || ft_strncmp(str, ">>", 3) == 0)
		return (REDIR);
	if (ft_strncmp(str, "|", 2) == 0)
		return (PIPE);
	if (is_word(str))
		return (WORD);
	return (INVALID);
}

// Returns a token (with its type) given a string representing it.
t_token	tok_create(const char *str)
{
	t_token	token;

	token.val = ft_strdup(str);
	token.type = tok_type(str);
	return (token);
}

// Returns a token of type NULL_TOK (used on special cases).
t_token	tok_create_null(void)
{
	t_token	token;

	token.val = ft_strdup("");
	token.type = NULL_TOK;
	return (token);
}

// Frees the 'token' node and its content.
void	tok_del(void *token)
{
	free(((t_token *)token)->val);
	free(token);
}

// Given a token list 'node' returns a pointer to its 'token' value.
t_token	*tok_get(t_list *node)
{
	if (!node)
		return (NULL);
	return ((t_token *)node->val);
}
