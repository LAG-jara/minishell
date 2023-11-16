/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:00:00 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/16 14:20:16 by glajara-         ###   ########.fr       */
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

// Prints the corresponding execution error message (according to errno).
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
}

// Prints the corresponding filename error message (according to errno).
void	print_err_filename(const char *filename)
{
	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(filename, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
}

// Prints an error message regarding the here document and returns a non-zero
// exit code.
int	print_err_heredoc()
{
	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd("here document error: ", STDERR_FILENO);
	return (EXIT_FAILURE);
}
