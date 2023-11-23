/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_print_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:00:00 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/22 12:44:09 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_error.h"

int	print_err_identifier(const char *identifier)
{
	// Error from unset
	//bash: unset: `_aaaa222asd=pepe': not a valid identifier
	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": unset: '", STDERR_FILENO);
	ft_putstr_fd(identifier, STDERR_FILENO);
	ft_putstr_fd("': ", STDERR_FILENO);
	ft_putendl_fd(MSG_IDENTERR, STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	print_err_too_many_arg(void)
{
	// Error form exit
	// bash: exit: too many arguments
	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putendl_fd(": exit: too many arguments", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	print_err_numeric_arg(const char *arg)
{
	// Error from exit
	// bash: exit: --1: numeric argument required
		ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(MSG_NUMARG, STDERR_FILENO);
	return (EXIT_NUMARG);
}


