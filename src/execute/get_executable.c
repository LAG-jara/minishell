/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_executable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:37:10 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/27 15:56:06 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_private.h"
#include "basic_utils.h"
#include "print_error.h"
#include "env.h"
#include <unistd.h>

// Allocates and returns a string containing the full path of 'file' in 'dir'.
// Example: if 'dir' is /folder and 'file' is myfile, returns "/folder/myfile".
static char	*get_full_path(const char *dir, const char *file)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(dir, "/");
	full_path = ft_strjoin(tmp, file);
	free(tmp);
	return (full_path);
}

// Searches for 'file' using the PATH env variable and returns the first
// full path for the executable file.
// If the file is not found or is not executable, prints an error and exits.
char	*get_executable(const char *file, char **env)
{
	char	*path;
	char	**paths;
	int		i;

	paths = env_get_vars("PATH", env);
	i = -1;
	while (paths && paths[++i])
	{
		path = get_full_path(paths[i], file);
		if (path_exists(path) && !is_directory(path))
		{
			if (can_execute(path))
				return (path);
			else
			{
				free(path);
				print_err_perm_denied(file);
				exit(EXIT_PERM_DENIED);
			}
		}
		free(path);
	}
	print_err_cmd_not_found(file);
	exit(EXIT_CMD_NOT_FOUND);
}
