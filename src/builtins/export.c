/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:03:34 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/20 17:23:54 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include "env.h"
#include "list.h"
#include "print_error.h"
#include <unistd.h>

static void	printvar_quoted(const char *var)
{
	while (*var != '=')
	{
		write(1, var, 1);
		++var;
	}
	write(1, "=\"", 2);
	++var;
	while (*var)
	{
		write(1, var, 1);
		++var;
	}
	write(1, "\"\n", 2);
}

// Prints the variables in env and reurns 0.
static int	export_noargs(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_strchr(env[i], '='))
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			printvar_quoted(env[i]);
		}
	}
	return (0);
}

// Export every variable in 'args' to env. 
// If no errors are found, returns 0.
// Otherwise returns error with the proper message and exit_status.
int	export_builtin(char **args, char ***env)
{
	char	*varname;
	int		i;
	int		exit_status;

	exit_status = 0;
	if (!*args)
		return (export_noargs(*env));
	--args;
	while (++args && *args)
	{
		i = 0;
		varname = env_get_varname(*args);
		if (!env_valid_varname(varname))
		{
			exit_status = print_err_identifier("export", *args);
			free(varname);
			continue ;
		}
		while ((*args)[i] && (*args)[i] != '=')
			++i;
		if ((*args)[i++] == '=')
			env_set_var(varname, (*args) + i, env);
		free(varname);
	}
	return (exit_status);
}
