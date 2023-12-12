/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:09:34 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/12 20:29:05 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tokens.h"

// Returns TRUE if the token at 'node' is a valid redirection token,
// returns FALSE otherwise.
static int	is_valid_redir(t_list *node)
{
	t_token	*next_tok;

	if (node->nxt == NULL)
		return (FALSE);
	next_tok = tok_get(node->nxt);
	if (next_tok->type != WORD)
		return (FALSE);
	return (TRUE);
}

// Returns TRUE if the token at 'node' is a valid pipe token,
// returns FALSE otherwise.
static int	is_valid_pipe(t_list *node)
{
	t_token	*prev_tok;
	t_token	*next_tok;

	if (node->pre == NULL || node->nxt == NULL)
		return (FALSE);
	next_tok = tok_get(node->nxt);
	prev_tok = tok_get(node->pre);
	if (prev_tok->type == WORD
		&& (next_tok->type == WORD || next_tok->type == REDIR))
		return (TRUE);
	else
		return (FALSE);
}

// Returns the amount of commands in the NULL-terminated 'tokens' array.
// If a syntax error is found, prints an error message and returns -1.
static int	count_commands_checking_syntax(t_list *tokens)
{
	int		tok_amount;
	int		cmd_amount;
	t_list	*node;
	t_token	*tok;

	tok_amount = lst_size(tokens);
	cmd_amount = 1;
	node = tokens;
	while (node)
	{
		tok = tok_get(node);
		if (tok->type == INVALID)
			return (print_err_syntax(tok->val, -1));
		if (tok->type == REDIR && !is_valid_redir(node))
			return (print_err_syntax(tok->val, -1));
		if (tok->type == PIPE)
		{
			++cmd_amount;
			if (!is_valid_pipe(node))
				return (print_err_syntax(tok->val, -1));
		}
		node = node->nxt;
	}
	return (cmd_amount);
}

// static void	hardcoding_foo(t_list *node)
// {
// 	t_list	*prev;
// 	t_list	*next;

// 	prev = node->pre;
// 	next = node->nxt;
// 	lst_delone(node, tok_del);
// 	lst_link(prev, next);
// }

// Creates and adds a new command to the 'cmd' list, adding all the tokens from
// 'node' until a PIPE is found (or there are no more tokens).
// At the end, 'node' points to the node after the PIPE (or NULL).
static void	add_cmd(t_list **cmd, t_list **node)
{
	t_list	*next_node;
	t_token	*tok;
	t_token tok_copy;

	*cmd = NULL;
	while (*node)
	{
		tok = tok_get(*node);
		if (tok->type != PIPE)
		{
			tok_copy = tok_create(tok->val);
			lst_add(cmd, lst_new(&tok_copy, sizeof(tok_copy)));
		}
		else
		{
			next_node = (*node)->nxt;
			// hardcoding_foo(*node);
			*node = next_node;
			return ;
		}
		*node = (*node)->nxt;
	}
	return ;
}

// Parses the list of tokens and splits them into an array of commands, using
// the PIPE token as a separator. Allocates and returns the array of commands.
// If a syntax error is found, prints an error message, 'exit_status' is set to 
// the corresponding value and returns NULL.
t_list	**parse(t_list *tokens, int *exit_status)
{
	int		cmd_amount;
	t_list	**cmds;
	int		i;
	t_list	*node;

	cmd_amount = count_commands_checking_syntax(tokens);
	if (cmd_amount == -1)
	{
		*exit_status = EXIT_SYNTERR;
		return (NULL);
	}
	cmds = (t_list **)p_malloc(sizeof(t_list *) * (cmd_amount + 1));
	i = -1;
	node = tokens;
	while (++i < cmd_amount)
		add_cmd(&cmds[i], &node);
	cmds[i] = NULL;
	return (cmds);
}
