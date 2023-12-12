/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:28:03 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/12 16:04:04 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "signal_handler.h"

// Frees a list of tokens
void	free_tokens(t_list **tokens)
{
	lst_clear(tokens, tok_del);
}

// Set the signal handling of the loop during the parse
static void set_interactive_sig(void)
{
	init_signals(INTER);
	ignore_signal(SIGQUIT);
}

// Executes the minish loop until the SIGHUP signal is received.
void	minish_loop(char **env)
{
	char	*input;
	t_list	*tokens;
	t_list	**commands;
	int		exit_status;

	exit_status = 0;
	while (42)
	{
		set_interactive_sig();
		input = get_input();
		ignore_signal(SIGINT);
		if (!input)
		{
			ft_putendl_fd("exit", STDERR_FILENO);
			exit(exit_status);
		}
		tokens = tokenize(input);
		free(input);
		commands = parse(tokens, &exit_status);
		if (!commands)
			continue ;
		commands = expand_and_split(commands, exit_status, env);
		redirect_and_execute(commands, &exit_status, &env);
		lst_clear(commands, tok_del);
		free (commands);
	}
}
