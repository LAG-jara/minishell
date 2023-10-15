/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:09:34 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/15 19:58:06 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "token_utils.h"
#include "minishell.h"

#include <stdio.h>


// Returns TRUE if the redirection token in the 'i'th position is valid,
// returns FALSE otherwise.
static int is_valid_redir(char **tokens, int i, int tok_amount)
{
	char	*next_token;

	if (i + 1 >= tok_amount)
		return (FALSE);
	next_token = tokens[i + 1];
	if (token_type(next_token) == WORD)
		return (TRUE);
	else
		return (FALSE);
}

// Returns TRUE if the control token in the 'i'th position is valid,
// returns FALSE otherwise.
static int is_valid_ctrl(char **tokens, int i, int tok_amount)
{
	char	*prev_token;
	char	*next_token;

	if (i + 1 >= tok_amount || i == 0)
		return (FALSE);
	next_token = tokens[i + 1];
	prev_token = tokens[i - 1];
	if (token_type(prev_token) == WORD &&
		(token_type(next_token) == WORD || token_type(next_token) == REDIR_OP))
		return (TRUE);
	else
		return (FALSE);
}

// Prints the a syntax error message regarding 'token' and returns 'ret'.
static int	print_syntax_err(char *token, int ret)
{
	printf("%s: syntax error near token '%s'\n", SH_NAME, token);
	return (ret);
}

// Returns the amount of commands in the NULL-terminated 'tokens' array.
// If a syntax error is found, prints an error message and returns -1.
static int	count_commands_checking_syntax(char **tokens)
{
	int		tok_amount;
	int		cmd_amount;
	int		i;

	tok_amount = get_strarr2_size(tokens);
	cmd_amount = 1;
	i = 0;
	while (i < tok_amount)
	{
		if (token_type(tokens[i]) == REDIR_OP
			&& !is_valid_redir(tokens, i, tok_amount))
			return (print_syntax_err(tokens[i], -1));
		if (token_type(tokens[i]) == CTRL_OP)
		{
			++cmd_amount;
			if (!is_valid_ctrl(tokens, i, tok_amount))
				return (print_syntax_err(tokens[i], -1));
		}
		if (token_type(tokens[i]) == INVALID)
			return (print_syntax_err(tokens[i], -1));
		++i;
	}
	return (cmd_amount);
}

// Parses the NULL-terminated array of tokens and groups them into a 
// NULL-terminated array of commands, dividing them by the single token '|'
// If a syntax error is found, prints an error message, the environment variable
// $? is set to the exit status of the last executed command and returns NULL.
char	***parse(char **tokens, char ***env)
{
	int		cmd_amount;
	char	*err_msg;	

	cmd_amount = count_commands_checking_syntax(tokens);
	if (cmd_amount == -1)
	{
		return (NULL);							// TODO: set $?
	}
	printf("CMD amount: %d\n", cmd_amount);
	return (NULL);
}

// int	main(void)
// {
// 	char *tokens[] = { "ls", "arg1", "arg2", "|", "echo", "", "command", "|", NULL};

// 	parse(tokens, NULL);

// 	// char	*token = "";
// 	// int		type = token_type(token);
// 	// printf("Type of '%s': %d\n", token, type);
// }