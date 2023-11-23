/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:31 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/22 18:14:37 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"
#include "heredoc.h"
#include "token_utils.h"

// Performs the redirection defined by 'redir', taking 'str' as the following 
// token. In the case of here documents, quote-removal is performed to 'str'.
// Returns the appropriate exit code after printing any error message.
static int	redirect_one(char *redir, char *str, char **env)
{
	int	expand;

	if (!ft_strncmp(redir, ">", 2))
		return (link_output_file(str, FALSE));
	else if (!ft_strncmp(redir, ">>", 3))
		return (link_output_file(str, TRUE));
	else if (!ft_strncmp(redir, "<", 2))
		return (link_input_file(str));
	else if (!ft_strncmp(redir, "<<", 3))
	{
		expand = delim_quote_remove(&str);
		return (link_heredoc(str, expand, env));
	}
	return (EXIT_FAILURE);
}

// Performs all redirections of the current command, from left-to-right,
// removing the redirection tokens from 'cmd'. Returns the exit status.
// If a redirection error ocurrs, prints an error message.
int	redirect(t_list **cmd, char **env)
{
	int		exit_stat;
	t_list	*node;
	t_token	tok;

	exit_stat = 0;
	node = *cmd;
	while (node && exit_stat == 0)
	{
		tok = tok_get(node);
		if (tok.type == REDIR && node->nxt)
		{
			exit_stat = redirect_one(tok.val, tok_get(node->nxt).val, env);
			lst_rm_many(cmd, node, 2, tok_del);
		}
		node = node->nxt;
	}
	return (exit_stat);
}
