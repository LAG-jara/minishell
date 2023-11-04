/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:28:03 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 16:57:14 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Executes the minish loop until the SIGHUP signal is received.
void	minish_loop(char **env)
{
	char	*input;
	char	**tokens;
	t_list	**commands;
	int		exit_status;

	exit_status = 0;
	while (42)
	{
		input = get_input();
		tokens = tokenize(input);
		commands = parse(tokens, &exit_status);
		if (!commands)
			continue ;
		commands = expand_and_split(commands, exit_status, env);
		redirect_and_execute(commands, &exit_status, &env);
	}
}   
