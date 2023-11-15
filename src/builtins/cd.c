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
#include "env.h"
#include <unistd.h>

static int	is_relativepath(char *str)
{
	if (str && str[0] != '/')
		return (TRUE);
	return (FALSE);
}

// Returns TRUE if can perform a change of dir with any path.
// FALSE otherwise.
static int	try_cdpath(char *str, char **path)
{
	int	i;

	i = -1;
	while (path[++i])
	{
		if (chdir())
	}
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
	written directory the standard output.
	The return value is true if the directory was successfully changed;
	false otherwise.
CDPATH
	The search path for the cd command. This is a colon-separated (`:') list of
	directories in which the shell looks for destination directories specified
	by the cd command. A sample value is ".:~:/usr".
*/

int	cd_builtin(char **word, char **env)
{
	int		i;
	int		ret;

	i = -1;
	// Mirar si word[0] es absoluto o relativo ('/' al inicio).
	// Si es retalivo, buscar en CDPATH word[0]. Si está, escibir el path.
	
	if (is_relativepath(*word))
	{
		if (try_cdpath(*word, get_vars("CDPATH" ,env)))
			return (pwd_builtin());
	}
	ret = chdir(*word);
	if (ret != 0)
		return (1);
	return (ret);
}

int


# include "debug.h"
# include "builtins.h"
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
}