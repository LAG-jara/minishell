/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:03:02 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/22 13:03:05 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include "builtins.h"
#include "definitions.h"
#include "env.h"
#include <unistd.h>

#include "get_next_line.h" // TODO : ver leaks porque no se yo

# include "debug.h"

static int	is_relativepath(char *str)
{
	if (str[0] != '/')
		return (TRUE);
	return (FALSE);
}

// If the string 'str' uses the dir . or .. returns TRUE.
// Otherwise returns FALSE.
static int is_same_or_parent_dir(char *str)
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
	path = get_vars("CDPATH" ,env);
	if (path == NULL)
		return (FALSE);
	while (path[++i])
	{
		gnl_strjoin_free(&path[i], str);
		if (chdir(path[i]) == 0)
		{
			arrstr_free(path);
			return(TRUE);
		}
	}
	arrstr_free(path);
	return(FALSE);
}

/*
cd [dir]
	Change the current directory to dir. The variable HOME is the default dir. 
	The variable CDPATH defines the search path for the directory 
	containing dir. 
	Alternative directory names in CDPATH are separated by a colon (:). 
	A null directory name in CDPATH is the same as the current directory, 
	i.e., ".".
	If dir begins with a slash (/), then CDPATH is not used. 
	If a non-empty directory name from CDPATH is used and the directory change 
	is successful, the absolute pathname of the new working directory is 
	written to the standard output.
	The return value is true if the directory was successfully changed;
	false otherwise.
CDPATH
	The search path for the cd command. This is a colon-separated (`:') list of
	directories in which the shell looks for destination directories specified
	by the cd command. A sample value is ".:~:/usr".
HOME
	The home directory of the current user; the default argument for the cd builtin 
	command. The value of this variable is also used when performing tilde expansion. 
*/

int	cd_builtin(char **word, char **env)
{
	int		i;
	int		ret;

	i = -1;
	// Mirar si word[0] es absoluto o relativo ('/' al inicio).
	// Si es retalivo, buscar en CDPATH word[0]. Si está, escibir el path.
	if (*word == NULL)
	{
		ret = chdir(get_var("HOME", env));
		if (ret != 0)
			return (1);
		return (ret);
	}
	if (is_relativepath(*word) && is_same_or_parent_dir(*word) == FALSE)
	{
		if (try_cdpath(*word, env))
			return (pwd_builtin());
	}
	ret = chdir(*word);
	if (ret != 0)
		return (1);
	return (ret);
}

//# include "debug.h"
//# include "builtins.h"
# include "parse_tokens.h"
int	main(int ac, char **av, char **e)
{
	char **env = arrstr_dup(e);
	ac += 0;
	av += 0;
	printf("-=-=-=-=-=-=-=-=-=-=--=-=-=-=\n");
	pwd_builtin();
	int err = cd_builtin(++av, env);
	pwd_builtin();
	printf("\t%d\n", err);
}