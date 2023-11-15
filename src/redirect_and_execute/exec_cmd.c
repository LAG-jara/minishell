/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:44:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/15 17:18:33 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "basic_utils.h"
# include "env.h"
# include "list.h"
# include "print_error.h"

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

// Executes the shell command 'cmd' and exits, assuming 'cmd' is a non-empty
// NULL-terminated array of strings in which the first element is the path or
// name of the program and the following (if any) are the arguments.
// On error, prints an error message and exits with the appropriate exit code.
void	exec_cmd(char **cmd, char **env)
{
	char	**paths;
	char	**args;
	char	*path;
	int		i;

	path = cmd[0];
	args = cmd;
	if (!ft_strchr(path, '/'))
	{
		paths = get_vars("PATH", env);
		i = -1;
		while (paths[++i])
		{
			path = get_full_path(paths[i], args[0]);
			execve(path, args, env);
			free(path);
		}
	}
	else
		execve(path, args, env);
	err_exec(cmd[0]);
}
