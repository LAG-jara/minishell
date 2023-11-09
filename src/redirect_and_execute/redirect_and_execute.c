/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_and_execute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:23:44 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/09 17:39:11 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_and_execute.h"
# include "token_utils.h"
# include "builtins.h"
# include "exec_cmd.h"

// Returns the size of the given NULL-terminated array.
static size_t	arr_size(void **arr)
{
	size_t	size;

	size = 0;
	while (arr && arr[size])
		++size;
	return (size);
}

// Allocates and returns a NULL-terminated array of strings representing the
// list of tokens 'cmd'.
static char	**get_args_from_cmd(t_list *cmd)
{
	char	**args;
	size_t	len;
	t_token	tok;
	int		i;

	len = lst_size(cmd);
	args = (char **)p_malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (cmd)
	{
		tok = tok_get(cmd);
		args[i++] = ft_strdup(tok.val);
		cmd = cmd->nxt;
	}
	args[i] = NULL;
	return (args);
}

// Redirects and executes the command 'cmd' in a subshell, exiting with the
// appropriate exit status.
void	process_command(t_list *cmd, char **env)
{
	int		exit_stat;
	char	**args;
	char	**e;

	exit_stat = redirect(&cmd);
	if (exit_stat != 0)
		exit(exit_stat);
	args = get_args_from_cmd(cmd);
	if (is_builtin_name(cmd))
	{
		e = arrstr_dup(env);
		exit_stat = exec_builtin(cmd, &e);
		arrstr_free(e);
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
	args = get_args_from_cmd(cmd);
	exit_stat = exec_builtin(args, env);
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
	else if (cmds_amount > 0)
	{
		// TODO: Process (redir & exec) commands on subshells.
	}
	// else ?
 }
