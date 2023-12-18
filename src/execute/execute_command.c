/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:21:54 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/18 13:26:38 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_private.h"
#include "token.h"
#include "builtins.h"
#include "arrstr.h"
#include "signal_utils.h"
#include "print_error.h"			// Remove when unused

// Prints an error message when trying to execute a null command and exits.
static void	exit_null_cmd()
{
	ft_putstr_fd(SH_NAME, STDERR_FILENO);			// TODO: move to print_error.h
	ft_putstr_fd(": : ", STDERR_FILENO);			//
	ft_putendl_fd(MSG_CMD_NOT_FOUND, STDERR_FILENO);//
	exit(EXIT_CMD_NOT_FOUND);
}

// Executes the command 'cmd' (which might be a builtin) assuming there are no
// redirections and exits with the appropriate exit status.
void	execute_command(t_list *cmd, int exit_status, char **env)
{
	int		exit_stat;
	char	**args;
	char	**e;

	set_signals(NON_INTER);
	// signals_print_handler(TRUE);
	args = get_args_from_cmd(cmd);
	if (ft_strlen(tok_get(cmd)->val) == 0)
		exit_null_cmd();
	if (is_builtin_name(args[0]))
	{
		e = arrstr_dup(env);
		exit_stat = exec_builtin(args, exit_status, &e, TRUE);
		arrstr_free(e);
		exit(exit_stat);
	}
	exec_cmd(args, env);
	exit(EXIT_FAILURE);
}
