/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:55:53 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/03 19:29:05 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
# include "debug.h"

int	main(int ac, char **av, char **e)	// TODO: only ac & getenv() ?
{
	char	**env;
	char	*input;
	char	**tokens;
	t_list	**commands;

	// if (ac != 1)
	// 	wrong_argc();
	env = arrstr_dup(e);
	while (42)
	{
		input = get_input();
		tokens = tokenize(input);
		commands = parse(tokens);
		if (!commands)
			continue ;
		commands = expand_and_split(commands, env);
		// redirect_and_execute(commands, &env);
	}
	return (0);
}
