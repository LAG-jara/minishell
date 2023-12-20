/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:04:19 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/20 12:41:36 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"
#include "basic_utils.h"
#include "list.h"
#include "token.h"

// Returns TRUE if the string 'str' is the name of a builtin.
int	is_builtin_name(const char *str)
{
	if (!ft_strncmp(str, "cd", 3) || !ft_strncmp(str, "echo", 5) || \
	!ft_strncmp(str, "env", 4) || !ft_strncmp(str, "exit", 5) || \
	!ft_strncmp(str, "export", 7) || !ft_strncmp(str, "pwd", 4) || \
	!ft_strncmp(str, "unset", 6))
		return (TRUE);
	return (FALSE);
}

// Returns TRUE if the list 'cmd' is suposed to execute a builtin.
int	is_builtin_cmd(t_list *cmd)
{
	t_list	*node;
	t_token	*tok;

	node = cmd;
	if (node)
	{
		tok = tok_get(node);
		while (tok->type == REDIR)
		{
			node = lst_move(node, 2);
			if (!node)
				return (FALSE);
			tok = tok_get(node);
		}
		if (is_builtin_name(tok->val))
			return (TRUE);
	}
	return (FALSE);
}

/*
*	'args' being a NULL-terminated array of strings, representing the arguments
*	passed to the builting (including its name).
*	The function must return the exit status of executing the builtin.
*	Incorrect arguments or errors on execution must be handled by the builtin
*	function, printing the error message and returning the expected value.
*/
int	exec_builtin(char **args, int exit_status, char ***env, int is_child)
{
	if (!ft_strncmp(args[0], "cd", 3))
		exit_status = cd_builtin(++args, *env);
	else if (!ft_strncmp(args[0], "echo", 5))
		exit_status = echo_builtin(++args);
	else if (!ft_strncmp(args[0], "env", 4))
		exit_status = env_builtin(*env);
	else if (!ft_strncmp(args[0], "exit", 5))
		exit_status = exit_builtin(++args, exit_status, is_child);
	else if (!ft_strncmp(args[0], "export", 7))
		exit_status = export_builtin(++args, env);
	else if (!ft_strncmp(args[0], "pwd", 4))
		exit_status = pwd_builtin();
	else if (!ft_strncmp(args[0], "unset", 6))
		exit_status = unset_builtin(++args, env);
	return (exit_status);
}
