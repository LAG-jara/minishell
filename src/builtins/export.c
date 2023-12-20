/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:03:34 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/20 14:13:13 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include "env.h"
#include "list.h"
#include "print_error.h"
#include <unistd.h>

/*
export name=value ...
	The value of the environment variable name is set to value. 
	If the environment variable name doesn’t exist it is created. 
	If no value is given after '=', the value will be set to ””. 
	export returns an exit status of 0 unless one of the names is not a valid 
	shell variable name.

	The text after the ‘=’ undergoes variable expansion and quote removal 
	(but NO word splitting after expansion) before being assigned to the 
	variable.

	If no arguments are pased, export prints all environtment variables with
	value between double-quotes.
*/
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

int	export_builtin(char **args, char ***env)
{
	char	*word;
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
		word = *args;
		varname = env_get_varname(word);
		if (!env_valid_varname(varname))
		{
			exit_status = print_err_identifier("export", word);
			free(varname);
			continue ;
		}
		while (word[i] && word[i] != '=')
			++i;
		if (word[i++] == '=')
			env_set_var(varname, word + i, env);
		free(varname);
	}
	return (exit_status);
}
