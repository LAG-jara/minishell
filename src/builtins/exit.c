/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:04:10 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/18 18:25:03 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_private.h"
#include "print_error.h"
#include "basic_utils.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_check_llong(char *arg)
{
	int		len;
	int		diff;
	char	sign;

	sign = '+';
	if (*arg == '-' || *arg == '+')
	{
		sign = *arg;
		arg++;
	}
	while (*arg == '0')
		arg++;
	len = ft_strlen(arg);
	if (len > 19)
		return (FALSE);
	if (len == 19)
	{
		if (sign == '-')
			diff = ft_strncmp(arg, LLINT_MIN_STR, 19);
		else
			diff = ft_strncmp(arg, LLINT_MAX_STR, 19);
		if (diff > 0)
			return (FALSE);
	}
	return (TRUE);
}
// Long long range: -9223372036854775808 > 9223372036854775807

static int	is_longlong(char *arg)
{
	int	i;

	i = 0;
	if (!*arg)
		return (FALSE);
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i + 1] == 0)
			return (FALSE);
		++i;
	}
	while (arg[i] == '0')
		++i;
	while (arg[i] && ((arg[i] <= '9' && arg[i] >= '0')))
		++i;
	if (arg[i])
		return (FALSE);
	return (ft_check_llong(arg));
}

// Exits the program. If is_child does not print exit when executed.
// If no args exits with the previous exit_status.
// If args is only one value inside long long range, returns its module of 256.
// Does its error behaviour.
int	exit_builtin(char **args, int exit_status, int is_child)
{
	long long	exit_stat;
	char		*str;

	if (!is_child)
		ft_putendl_fd("exit", STDERR_FILENO);
	if (*args == NULL)
		restore_exit(exit_status);
	str = ft_strtrim(args[0], " \n\t\v\f\r");
	if (is_longlong(str) == FALSE)
	{
		free(str);
		restore_exit(print_err_numeric_arg(args[0]));
	}
	if (args[1] == NULL)
	{
		exit_stat = ft_atoll(str);
		free(str);
		restore_exit(exit_stat % 256);
	}
	free(str);
	return (print_err_too_many_arg());
}
