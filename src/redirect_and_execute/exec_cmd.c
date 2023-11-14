/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:44:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/14 18:26:42 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmd.h"
#include "token_utils.h"

// Prints the corresponding error message (according to errno).
static void	err_exec(char *cmdname)
{
	char	*tmp;

	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (errno == ENOENT)
		tmp = ft_strdup("Command not found");
	else
		tmp = ft_strdup(strerror(errno));
	ft_putstr_fd(tmp, STDERR_FILENO);
	free(tmp);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(cmdname, STDERR_FILENO);
	// if (errno == ENOENT)
	// 	exit(CMD_NOT_FOUND);
	// exit(errno);
}

// Allocates and returns a string containing the full path of 'file' in 'dir'.
// Example: if 'dir' is /folder and 'file' is myfile, returns "/folder/myfile".
static char	*get_full_path(char *dir, char *file)
{
	char	*tmp;
	char	*full_path;

	tmp = ft_strjoin(dir, "/");
	full_path = ft_strjoin(tmp, file);
	free(tmp);
	return (full_path);
}

// Executes the shell command 'cmd' and exits.
// If it can't be opened, prints an error message and 'errno' is set.
void	exec_cmd(char **cmd, char **env)
{
	char	**paths;
	char	**args;
	int		i;

	args = ft_split(cmd, ' ');
	if (ft_strncmp(cmd, "./", 2) == 0)
		execve(cmd, args, env);
	else
	{
		paths = get_vars("PATH", env);
		i = -1;
		while (paths[++i])
		{
			cmd = get_full_path(paths[i], args[0]);
			execve(cmd, args, env);
			free(cmd);
		}
	}
	err_exec(args[0]);
}
