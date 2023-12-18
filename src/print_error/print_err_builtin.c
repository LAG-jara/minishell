/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:00:00 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/18 18:43:16 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_error.h"
#include "basic_utils.h"
#include "minish_consts.h"
#include <string.h>
#include <unistd.h>
#include <errno.h>

int	print_err_builtin(const char *builtin, const char *arg)
{
	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(builtin, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (arg)
	{
		ft_putstr_fd("'", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd("': ", STDERR_FILENO);
	}
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	print_err_too_many_arg(void)
{
	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putendl_fd(": exit: too many arguments", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	print_err_identifier(const char *builtin, const char *identifier)
{
	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(builtin, STDERR_FILENO);
	ft_putstr_fd(": '", STDERR_FILENO);
	ft_putstr_fd(identifier, STDERR_FILENO);
	ft_putstr_fd("': ", STDERR_FILENO);
	ft_putendl_fd(MSG_IDENTERR, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	print_err_numeric_arg(const char *arg)
{
	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(MSG_NUMARG, STDERR_FILENO);
	return (EXIT_NUMARG);
}
