/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:31 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/12 15:27:45 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"
#include "heredoc.h"
#include "token_utils.h"

// Performs the redirection defined by 'redir', taking 'str' as the following 
// token. In the case of here documents, quote-removal is performed to 'str'.
// Returns the appropriate exit code after printing any error message.
static int	redirect_one(char *redir, char *str)
{
	if (!ft_strncmp(redir, ">", 2))
		return (link_output_file(str, FALSE));
	else if (!ft_strncmp(redir, ">>", 3))
		return (link_output_file(str, TRUE));
	else if (!ft_strncmp(redir, "<", 2))
		return (link_input_file(str));
	else if (!ft_strncmp(redir, "<<", 3))
		return (link_heredoc());
	return (EXIT_FAILURE);
}

// Reads the here documents for 'cmd' from left to right, into a temp file.
// If there's more than one here document, the previous ones are overwritten.
// Returns 0 on success. Otherwise, returns a non-zero value after printing
// an error message.
static int	read_heredocs(t_list *cmd, char **env)
{
	t_list	*node;
	t_token	*tok;
	char	*delim;
	int		expand;

	node = cmd;
	while (node)
	{
		tok = tok_get(node);
		if (tok->type == REDIR && !ft_strncmp(tok->val, "<<", 3))
		{
			delim = tok_get(node->nxt)->val;
			expand = !has_quotes(delim);
			delim_quote_remove(&delim);
			if (read_heredoc(delim, expand, env))
				return (print_err_heredoc());
		}
		node = node->nxt;
	}
	return (EXIT_SUCCESS);
}

// Performs all redirections of the current command, from left-to-right,
// removing the redirection tokens from 'cmd'. Returns the exit status.
// If a redirection error ocurrs, prints an error message.
int	redirect(t_list **cmd, char **env)
{
	int		exit_stat;
	t_list	*node;
	t_list	*nxt_node;
	t_token	*tok;

	exit_stat = read_heredocs(*cmd, env);
	node = *cmd;
	while (node && exit_stat == 0)
	{
		tok = tok_get(node);
		if (tok->type == REDIR)
		{
			exit_stat = redirect_one(tok->val, tok_get(node->nxt)->val);
			nxt_node = lst_move(node, 2);
			lst_rm_many(cmd, node, 2, tok_del);
			node = nxt_node;
		}
		else
			node = node->nxt;
	}
	return (exit_stat);
}
