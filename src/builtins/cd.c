/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:03:02 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/20 12:51:13 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include "arrstr.h"
#include "builtins_private.h"
#include "env.h"
#include "print_error.h"

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
// If no arg is set, search for the variable PATH.
// If there is a relative path and its in dir, tries with variable CDPATH
// If it can perform the operation with CDPATH prints pwd.
// If some error is found exits with the proper message asociated.
int	cd_builtin(char **word, char **env)
{
	if (*word == NULL)
	{
		if (chdir(env_get_var("HOME", env)) < 0)
			return (print_err_builtin("cd", *word));
		return (EXIT_SUCCESS);
	}
	if (**word == '\0')
		return (EXIT_SUCCESS);
	if (is_relativepath(*word) && is_same_or_parent_dir(*word) == FALSE)
	{
		if (try_cdpath(*word, env))
			return (pwd_builtin());
	}
	if (chdir(*word) < 0)
		return (print_err_builtin("cd", *word));
	return (EXIT_SUCCESS);
}
