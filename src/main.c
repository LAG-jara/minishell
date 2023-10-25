/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:55:53 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/25 16:57:11 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
# include "debug.h"

int	main(int ac, char **av, char **environ)
{
	char	**env;
	char	*input;
	char	**tokens;
	char	***commands;

	ac++;
	av[0][0] = '.';
	env = strarr2_dup(environ);
	while (42)
	{
		input = get_input();
		printf("INPUT:\n%s\n\n", input);
		tokens = tokenize(input);
		print_strarr(tokens);
		printf("---------------------\n\n");
		commands = parse(tokens);
		if (!commands)
			continue ;
		print_cmds(commands);
		// commands = expand_and_split(commands, env);
		// redirect_and_execute(commands, &env);
		// print_cmds(commands);
		// printf("---------------------\n\n");
	}
	return (0);
}
