/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:44:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/27 17:06:02 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_private.h"
#include "basic_utils.h"
#include "env.h"
#include "print_error.h"
#include <errno.h>
#include <unistd.h>

// If the given 'path' is not executable, prints an error message and exits.
static void	check_path(const char *path)
{
	if (!path_exists(path))
	{
		print_err_nofile(path);
		exit(EXIT_NOFILE);
	}
	if (is_directory(path))
	{
		print_err_isdir(path);
		exit(EXIT_IS_DIR);
	}
	if (!can_execute(path))
	{
		print_err_perm_denied(path);
		exit(EXIT_PERM_DENIED);
	}
}

// Executes the shell command 'cmd' and exits, assuming 'cmd' is a non-empty
// NULL-terminated array of strings in which the first element is the path or
// name of the program and the following (if any) are the arguments.
// On error, prints an error message and exits with the appropriate exit code.
void	exec_cmd(char **cmd, char **env)
{
	char	**args;
	char	*path;

	path = cmd[0];
	args = cmd;
	if (!ft_strchr(path, '/'))
		path = get_executable(path, env);
	else
		check_path(path);
	execve(path, args, env);
	print_err_exec(cmd[0]);
	exit(EXIT_FAILURE);
}
