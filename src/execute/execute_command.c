/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:21:54 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/18 18:14:14 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_private.h"
#include "basic_utils.h"
#include "token.h"
#include "builtins.h"
#include "arrstr.h"
#include "signal_utils.h"
#include "print_error.h"

// Executes the command 'cmd' (which might be a builtin) assuming there are no
// redirections and exits with the appropriate exit status.
void	execute_command(t_list *cmd, int exit_status, char **env)
{
	int		exit_stat;
	char	**args;
	char	**e;

	set_signals(NON_INTER);
	args = get_args_from_cmd(cmd);
	if (ft_strlen(tok_get(cmd)->val) == 0)
	{
		print_err_null_cmd();
		exit(EXIT_CMD_NOT_FOUND);
	}
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
