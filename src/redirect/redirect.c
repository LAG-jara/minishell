/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:49:31 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/27 16:29:00 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_private.h"
#include "basic_utils.h"
#include "token.h"
#include "print_error.h"
#include <stdlib.h>

// Performs the redirection defined by 'redir', taking 'next' as the following 
// token, knowing it's the 'n'-th command.
// In the case of here documents, quote-removal is performed.
// Returns the appropriate exit code after printing any error message.
static int	redirect_one(char *redir, t_list *next, int n)
{
	char	*str;

	if (!next)
	{
		print_err_redir();
		return (EXIT_AMBIG_REDIR);
	}
	str = tok_get(next)->val;
	if (!ft_strncmp(redir, ">", 2))
		return (link_output_file(str, FALSE));
	else if (!ft_strncmp(redir, ">>", 3))
		return (link_output_file(str, TRUE));
	else if (!ft_strncmp(redir, "<", 2))
		return (link_input_file(str));
	else if (!ft_strncmp(redir, "<<", 3))
		return (link_heredoc(n));
	return (EXIT_FAILURE);
}

// Performs all redirections of 'cmd', from left-to-right, removing the
// redirection tokens, knowing it's the 'n'-th command. Returns the exit status.
// If a redirection error ocurrs, prints an error message.
int	redirect(t_list **cmd, int n)
{
	int		exit_stat;
	t_list	*node;
	t_list	*nxt_node;
	t_token	*tok;

	exit_stat = 0;
	node = *cmd;
	while (node && exit_stat == 0)
	{
		tok = tok_get(node);
		if (tok->type == REDIR)
		{
			exit_stat = redirect_one(tok->val, node->nxt, n);
			nxt_node = lst_move(node, 2);
			lst_rm_many(cmd, node, 2, tok_del);
			node = nxt_node;
		}
		else
			node = node->nxt;
	}
	return (exit_stat);
}
