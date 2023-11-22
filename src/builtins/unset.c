/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:03:52 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/26 12:26:06 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
/*
unset [name ...]
	For each name, remove the corresponding variable. 
	Each name refers to a shell variable. Read-only variables may not be unset.
	Each unset variable is removed from the environment passed to subsequent 
	commands. 
	The exit status is true unless a name is readonly.
*/

int	unset_builtin(char **args, char ***env)
{
	int	i;

	i = -1;
	// while (argv[++i])
	// 	rm_env_var(argv[i], env);
	// return (0);

	while (args[++i])
	{
		if (valid_varname(args[i]))
			rm_env_var(varname, word + i, env);
		else
			print_err_identifier(); // "bash: unset: `_a=pepe': not a valid identifier"
	}
	return (0);
}

// # include "debug.h"
// # include "builtins.h"
// # include "parse_tokens.h"

// int	main(int ac, char **av, char **e)
// {
// 	char **env = arrstr_dup(e);
// 	ac += 0;
// 	av += 0;
// 	unset_builtin(++av, &env);
// 	env_builtin(env);
// }