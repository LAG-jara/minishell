/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:04:02 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/22 13:04:03 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <unistd.h>
/*
env
	Prints the current environment.
*/

void	printvar(char *var)
{
	while (*var)
	{
		write(1, var, 1);
		var++;
	}
	write(1, "\n", 1);
}

void	env_builtin(char **env)
{
	while (*env)
	{
		if (ft_strchr(*env, '='))
			printvar(*env);
		env++;
	}
}

// # include "debug.h"
// # include "arrstr_utils.h"
// # include "parse_tokens.h"
// int	main(int ac, char **av, char **e)
// {
// 	char **env = arrstr_dup(e);
// 	ac += 0;
// 	av += 0;

// 	char *pre_toks[] = \
// 	{ "hola", "final", NULL};

// 	t_list	**cmds;
// 	cmds = parse(pre_toks);
// 	//if (cmds)
// 	//	print_cmds(cmds);

// 	env_builtin(env);
// 	lst_clear(cmds, tok_del);
// 	free(cmds);
// }