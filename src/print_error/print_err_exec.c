/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:11:53 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/29 17:14:39 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_error.h"

// Prints the corresponding execution error message (according to errno).
void	print_err_exec(const char *cmdname)
{
	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(cmdname, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (errno == ENOENT)
		ft_putendl_fd(MSG_CMD_NOT_FOUND, STDERR_FILENO);
	else
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
}

// Prints the error message for when trying to execute a command using an
// unset PATH variable.
void	print_err_nopath(const char *cmdname)
{
	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(cmdname, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(MSG_NOPATH, STDERR_FILENO);
}
