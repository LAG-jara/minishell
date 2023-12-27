/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:03:02 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/21 11:16:37 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include "arrstr.h"
#include "builtins_private.h"
#include "env.h"
#include "print_error.h"

// Makes sure the pointed 'path' string ends in '/'
static void	end_in_slash(char **path)
{
	if ((*path)[ft_strlen(*path)] != '/')
		ft_strjoin_free(path, "/");
}

static int	is_relativepath(char *str)
{
	if (str[0] != '/')
		return (TRUE);
	return (FALSE);
}

// If the string 'str' uses the dir "." or ".." returns TRUE.
// Otherwise returns FALSE.
static int	is_same_or_parent_dir(char *str)
{
	if (str[0] != '.')
		return (FALSE);
	if (str[1] == '\0' || str[1] == '/')
		return (TRUE);
	if (str[1] == '.' && (str[2] == '\0' || str[2] == '/'))
		return (TRUE);
	return (FALSE);
}

// Tries to change directory for any 'path' with 'str' at the end.
// If it succeeds, stops trying and retuns TRUE.
// FALSE otherwise.
static int	try_cdpath(char *str, char **env)
{
	char	**path;
	int		i;

	i = -1;
	path = env_get_vars("CDPATH", env);
	if (path == NULL)
		return (FALSE);
	while (path[++i])
	{
		end_in_slash(&path[i]);
		ft_strjoin_free(&path[i], str);
		if (chdir(path[i]) == 0)
		{
			arrstr_free(path);
			return (TRUE);
		}
	}
	arrstr_free(path);
	return (FALSE);
}

// Changes the actual dir. 
// If no 'args' is set, search for the env variable PATH.
// The first element of 'args' is taken as the new path.
// It it is a relative path tries appending CDPATH values, printing the current
// working dir on success.
// If some error is found returns after printing an error message.
int	cd_builtin(char **args, char **env)
{
	if (*args == NULL)
	{
		if (chdir(env_get_var("HOME", env)) < 0)
			return (print_err_builtin("cd", *args));
		return (EXIT_SUCCESS);
	}
	if (**args == '\0')
		return (EXIT_SUCCESS);
	if (is_relativepath(*args) && is_same_or_parent_dir(*args) == FALSE)
	{
		if (try_cdpath(*args, env))
			return (pwd_builtin());
	}
	if (chdir(*args) < 0)
		return (print_err_builtin("cd", *args));
	return (EXIT_SUCCESS);
}
