/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:04:02 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/15 15:05:51 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <unistd.h>

static void	printvar(const char *var)
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
// # include "arrstr.h"
// # include "parse_tokens.h"
// int	main(int ac, char **av, char **e)
// {
// 	char **env = arrstr_dup(e);
// 	ac += 0;
// 	av += 0;

// 	env_builtin(env);
// 	env_free(env);
// }