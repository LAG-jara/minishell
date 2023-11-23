/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:58:14 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/04 11:39:43 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "basic_utils.h"

/*
*	'args' being a NULL-terminated array of strings, representing the arguments
*	passed to the builting (including its name).
*	The function must return the exit status of executing the builtin.
*	Incorrect arguments or errors on execution must be handled by the builtin
*	function, printing the error message and returning the expected value.
*/
int	exec_builtin(char **args, int exit_status, char ***env)
{
	if (!ft_strncmp(args[0], "cd", 3))
		exit_status = cd_builtin(++args, *env);
	else if (!ft_strncmp(args[0], "echo", 5))
		exit_status = echo_builtin(++args);
	else if (!ft_strncmp(args[0], "env", 4))
		exit_status = env_builtin(*env);
	else if (!ft_strncmp(args[0], "exit", 5))
		exit_status = exit_builtin(++args, exit_status);
	else if (!ft_strncmp(args[0], "export", 7))
		exit_status = export_builtin(++args, env);
	else if (!ft_strncmp(args[0], "pwd", 4))
		exit_status = pwd_builtin();
	else if (!ft_strncmp(args[0], "unset", 6))
		exit_status = unset_builtin(++args, env);
	return (exit_status);
}
