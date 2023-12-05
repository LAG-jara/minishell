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
#include "print_error.h"
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
	int ret_status;

	i = -1;
	ret_status = 0;
	while (args[++i])
	{
		if (valid_varname(args[i]))
			rm_env_var(args[i], env);
		else
			ret_status = print_err_identifier(args[i]); // "bash: unset: `_a=pepe': not a valid identifier"
	}
	return (ret_status);
}
