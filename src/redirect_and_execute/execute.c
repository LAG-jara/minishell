/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:21:54 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/12 17:40:09 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include "token_utils.h"
#include "builtins.h"
#include "arrstr.h"
#include "signal_handler.h"

// Allocates and returns a NULL-terminated array of strings representing the
// list of tokens 'cmd'.
static char	**get_args_from_cmd(t_list *cmd)
{
	char	**args;
	size_t	len;
	t_token	*tok;
	int		i;

	len = lst_size(cmd);
	args = (char **)p_malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (cmd)
	{
		tok = tok_get(cmd);
		args[i++] = ft_strdup(tok->val);
		cmd = cmd->nxt;
	}
	args[i] = NULL;
	return (args);
}

// Executes the builtin defined by 'cmd' assuming there are no redirections and
// modifying the 'env' if required. Returns the exit status.
int	execute_builtin(t_list *cmd, int exit_status, char ***env)
{
	char	**args;
	int		exit_stat;

	args = get_args_from_cmd(cmd);
	exit_stat = exec_builtin(args, exit_status, env);
	return (exit_stat);
}


// Executes the command 'cmd' (which might be a builtin) assuming there are no
// redirections and exits with the appropriate exit status.
void	execute_command(t_list *cmd, int exit_status, char **env)
{
	int		exit_stat;
	char	**args;
	char	**e;

	init_signals(NON_INTER);
	args = get_args_from_cmd(cmd);
	if (is_builtin_name(args[0]))
	{
		e = arrstr_dup(env);
		exit_stat = exec_builtin(args, exit_status, &e);
		arrstr_free(e);
		exit(exit_stat);
	}
	exec_cmd(args, env);
	exit(EXIT_FAILURE);
}
