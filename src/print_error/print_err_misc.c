/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:00:00 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/29 17:12:12 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_error.h"

// Prints the a syntax error message regarding 'token' and returns 'ret'.
int	print_err_syntax(const char *token, int ret)
{
	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(MSG_SYNTERR, STDERR_FILENO);
	ft_putstr_fd(" '", STDERR_FILENO);
	ft_putstr_fd(token, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
	return (ret);
}

// Prints the an error message regarding a wrong arguments amount and returns
// the corresponding exit code.
int	print_err_argc(void)
{
	printf("%s: %s\n", SH_NAME, MSG_WRONGAC);
	return (EXIT_WRONGAC);
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
int	print_err_heredoc(void)
{
	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(MSG_HEREDOC_ERR, STDERR_FILENO);
	return (EXIT_FAILURE);
}