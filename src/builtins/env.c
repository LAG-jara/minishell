/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:04:02 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/03 19:58:26 by glajara-         ###   ########.fr       */
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

void	env_builtin(const char **env)
{
	while (*env)
	{
		if (ft_strchr(*env, '='))
			printvar(*env);
		env++;
	}
}

# include "debug.h"
# include "arrstr.h"
# include "parse_tokens.h"
int	main(int ac, char **av, const char **e)
{
	const char **env = (const char **)arrstr_dup(e);
	ac += 0;
	av += 0;

	//if (cmds)
	//	print_cmds(cmds);

	env_builtin(env);
}