/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:21:54 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/14 12:40:12 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

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

// Executes the builtin defined by 'cmd' assuming there are no redirections and
// modifying the 'env' if required. Returns the exit status.
int	execute_builtin(t_list *cmd, char ***env)
{
	char	*args;
	int		exit_stat;

	args = get_args_from_cmd(cmd);
	exit_stat = exec_builtin(args, env);
	return (exit_stat);
}

// Executes the command 'cmd' (which might be a builtin) assuming there are no
// redirections and exits with the appropriate exit status.
void	execute_command(t_list *cmd, char **env)
{
	int		exit_stat;
	char	**args;
	char	**e;

	args = get_args_from_cmd(cmd);
	if (is_builtin_name(cmd))
	{
		e = arrstr_dup(env);
		exit_stat = exec_builtin(args, &e);
		arrstr_free(e);
		exit(exit_stat);
	}
	exec_cmd(args, env);
	exit(EXIT_FAILURE);
}