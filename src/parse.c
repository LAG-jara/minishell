/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:09:34 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/18 13:52:42 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
# include "print_error.h"
# include "token_utils.h"
# include "errno.h"

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

// Returns the amount of commands in the NULL-terminated 'tokens' array.
// If a syntax error is found, prints an error message and returns -1.
static int	count_commands_checking_syntax(char **tokens)
{
	int		tok_amount;
	int		cmd_amount;
	int		i;

	tok_amount = strarr2_get_size(tokens);
	cmd_amount = 1;
	i = 0;
	while (i < tok_amount)
	{
		if (token_type(tokens[i]) == REDIR_OP
			&& !is_valid_redir(tokens, i, tok_amount))
			return (print_err_syntax(tokens[i], -1));
		if (token_type(tokens[i]) == CTRL_OP)
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

// Parses the array of tokens and groups them into an array of commands,
// dividing them by the token '|'. Allocates and returns the array of commands.
// If a syntax error is found, prints an error message,
// 'errno' is set to the corresponding value and returns NULL.
char	***parse(char **tokens)
{
	int		cmd_amount;
	char	*err_msg;	

	cmd_amount = count_commands_checking_syntax(tokens);
	if (cmd_amount == -1)
	{
		errno = ERRNO_SYNTAX;
		return (NULL);
	}
	printf("CMD amount: %d\n", cmd_amount);
	return (NULL);
}

// int	main(void)
// {
// 	char *tokens[] = { "ls", "arg1", "arg2", "|", "echo", "", "command", "arg", NULL};

// 	printf("Errno is: %d\n", errno);
// 	parse(tokens);
// 	printf("Errno is: %d\n", errno);

// 	// char	*token = "";
// 	// int		type = token_type(token);
// 	// printf("Type of '%s': %d\n", token, type);
// }