/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_and_execute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:23:44 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 19:41:45 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_and_execute.h"
# include "token_utils.h"
# include "builtins.h"
# include "exec_cmd.h"

static size_t	arr_size(void **arr)
{
	size_t	size;

	size = 0;
	while (arr && arr[size])
		++size;
	return (size);
}

// Redirects and executes the command 'cmd' in a subshell, exiting with the
// appropriate exit status.
void	process_command(t_list *cmd, char **env)
{
	int		exit_stat;

	exit_stat = redirect(&cmd);
	if (exit_stat != 0)
		exit(exit_stat);
	// args = get_args_from_cmd(cmd);		// TODO
	if (is_builtin_name(cmd))
	{
		exit_stat = exec_builtin(cmd, env);
		exit(exit_stat);
	}
	exec_cmd(cmd, env);
}

// Redirects and executes the given command 'cmd' on the current shell
// environment, returning the exit status.
int	process_builtin_here(t_list *cmd, char ***env)
{
	char	*args;
	int		exit_stat;


	exit_stat = redirect(&cmd);
	if (exit_stat != 0)
		return (exit_stat);
	// args = get_args_from_cmd(cmd);		// TODO
	exit_stat = exec_builtin(args, env);

	// TODO
	return (exit_stat);
}

// Performs all redirections and command/builtin executions defined by the array
// of lists 'commands', updating the 'exit_status' and environment 'env'
// accordingly.
void	redirect_and_execute(t_list **commands, int *exit_status, char ***env)
{
	int	cmds_amount;

	cmds_amount = arr_size((void *)commands);
	if (cmds_amount == 1 && is_builtin_cmd(commands[0]))
		*exit_status = process_builtin_here(commands[0], env);
	else if (cmds_amount > 1)
	{
		// TODO: Process (redir & exec) commands on subshells.
	}
	// else ?
 }
