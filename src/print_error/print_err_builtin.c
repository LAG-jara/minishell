/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:00:00 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/29 17:11:26 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_error.h"

int	print_err_builtin(const char *builtin, const char *arg)
{
	// Error from unset
	//bash: export: `42=asd': not a valid identifier
	//bash: unset: `_aaaa222asd=pepe': not a valid identifier
	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(builtin, STDERR_FILENO);
	if (arg)
	{
		ft_putstr_fd(": '", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd("': ", STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd(builtin, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}	
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	return (EXIT_FAILURE);
}


int  print_err_too_many_arg(void)
{
  // Error form exit
  // bash: exit: too many arguments
  ft_putstr_fd(SH_NAME, STDERR_FILENO);
  ft_putendl_fd(": exit: too many arguments", STDERR_FILENO);
  return (EXIT_FAILURE);
}

int  print_err_identifier(const char *builtin, const char *identifier)
{
  //bash: export: `42=asd': not a valid identifier
  //bash: unset: `_aaaa222asd=pepe': not a valid identifier
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
	// Error from exit
	// bash: exit: --1: numeric argument required
		ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(MSG_NUMARG, STDERR_FILENO);
	return (EXIT_NUMARG);
}

// int	print_err_cd(const char *arg, const char *err_msg)
// {
// 	ft_putstr_fd(SH_NAME, STDERR_FILENO);
// 	ft_putstr_fd(": cd: ", STDERR_FILENO);
// 	ft_putstr_fd(arg, STDERR_FILENO);
// 	ft_putstr_fd(": ", STDERR_FILENO);
// 	ft_putendl_fd(err_msg, STDERR_FILENO);
// 	return (EXIT_FAILURE);
// }


