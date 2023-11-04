/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:09:34 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 16:39:15 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tokens.h"

// Returns TRUE if the redirection token in the 'i'th position is valid,
// returns FALSE otherwise.
static int	is_valid_redir(char **tokens, int i, int tok_amount)
{
	char	*next_tok;

	if (i + 1 >= tok_amount)
		return (FALSE);
	next_tok = tokens[i + 1];
	if (token_type(next_tok) == WORD)
		return (TRUE);
	else
		return (FALSE);
}

// Returns TRUE if the control token in the 'i'th position is valid,
// returns FALSE otherwise.
static int	is_valid_ctrl(char **tokens, int i, int tok_amount)
{
	char	*prev_tok;
	char	*next_tok;

	if (i + 1 >= tok_amount || i == 0)
		return (FALSE);
	next_tok = tokens[i + 1];
	prev_tok = tokens[i - 1];
	if (token_type(prev_tok) == WORD
		&& (token_type(next_tok) == WORD || token_type(next_tok) == REDIR))
		return (TRUE);
	else
		return (FALSE);
}

// Returns the amount of commands in the NULL-terminated 'tokens' array.
// If a syntax error is found, prints an error message and returns -1.
static int	count_commands_checking_syntax(char **tokens)
{
	int		tok_amount;
	int		cmd_amount;
	int		i;

	tok_amount = arrstr_size(tokens);
	cmd_amount = 1;
	i = 0;
	while (i < tok_amount)
	{
		if (token_type(tokens[i]) == REDIR
			&& !is_valid_redir(tokens, i, tok_amount))
			return (print_err_syntax(tokens[i], -1));
		if (token_type(tokens[i]) == PIPE)
		{
			++cmd_amount;
			if (!is_valid_ctrl(tokens, i, tok_amount))
				return (print_err_syntax(tokens[i], -1));
		}
		if (token_type(tokens[i]) == INVALID)
			return (print_err_syntax(tokens[i], -1));
		++i;
	}
	return (cmd_amount);
}

static t_list	*get_cmd(t_list **cmd, char **tokens, int *j)
{
	t_token	tok;
	int		i;

	i = 0;
	*cmd = NULL;
	while (tokens[++(*j)])
	{
		tok = token_create(tokens[*j]);
		if (tok.type != PIPE)
		{
			lst_add(cmd, lst_new(&tok, sizeof(tok)));
		}
		else
			return (*cmd);
	}
	return (*cmd);
}

// Parses the array of tokens and groups them into an array of commands,
// dividing them by the token '|'. Allocates and returns the array of commands.
// If a syntax error is found, prints an error message, 'exit_status' is set to 
// the corresponding value and returns NULL.
t_list	**parse(char **tokens, int *exit_status)
{
	int		cmd_amount;
	t_list	**cmds;
	int		i;
	int		j;

	cmd_amount = count_commands_checking_syntax(tokens);
	if (cmd_amount == -1)
	{
		*exit_status = EXIT_SYNTERR;
		return (NULL);
	}
	cmds = (t_list **) p_malloc(sizeof(t_list *) * (cmd_amount + 1));
	j = -1;
	i = -1;
	while (++i < cmd_amount)
		get_cmd(&cmds[i], tokens, &j);
	cmds[i] = NULL;
	return (cmds);
}
