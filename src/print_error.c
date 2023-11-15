/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:00:00 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/15 15:35:35 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_error.h"

// Prints the a syntax error message regarding 'token' and returns 'ret'.
int	print_err_syntax(const char *token, int ret)
{
	printf("%s: %s '%s'\n", SH_NAME, MSG_SYNTERR, token);
	return (ret);
}

// Prints the an error message regarding a wrong arguments amount and returns
// the corresponding exit code.
int	print_err_argc()
{
	printf("%s: %s\n", SH_NAME, MSG_WRONGAC);
	return (EXIT_WRONGAC);
}

// Prints the corresponding error message (according to errno).
void	print_err_exec(const char *cmdname)
{
	char	*tmp;

	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (errno == ENOENT)
		tmp = ft_strdup("Command not found");
	else
		tmp = ft_strdup(strerror(errno));
	ft_putstr_fd(tmp, STDERR_FILENO);
	free(tmp);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(cmdname, STDERR_FILENO);
	if (errno == ENOENT)
		exit(EXIT_CMD_NOT_FOUND);
	exit(errno);
}
