/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:55:53 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/26 14:12:03 by glajara-         ###   ########.fr       */
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
	env = arrstr_dup(environ);
	int i = 1;
	while (i-- > 0)
	{
		//input = get_input();
		input = " $nada | $nada | $nada";
		// printf("INPUT:\n%s\n\n", input);
		tokens = tokenize(input);
		// print_strarr(tokens);
		// printf("---------------------\n\n");
		commands = parse(tokens);
		if (!commands)
			continue ;
		//print_cmds(commands);
		// printf("------ AFTER EXPANSION -------\n\n");
		commands = expand_and_split(commands, env);
		print_cmds(commands);
		// redirect_and_execute(commands, &env);
	}
	return (0);
}
