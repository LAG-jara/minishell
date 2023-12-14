/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:21:54 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:56:48 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_private.h"
#include "builtins.h"
#include "arrstr.h"

// Executes the builtin defined by 'cmd' assuming there are no redirections and
// modifying the 'env' if required. Returns the exit status.
int	execute_builtin(t_list *cmd, int exit_status, char ***env, int is_child)
{
	char	**args;
	int		exit_stat;

	args = get_args_from_cmd(cmd);
	exit_stat = exec_builtin(args, exit_status, env, is_child);
	arrstr_free(args);
	return (exit_stat);
}
