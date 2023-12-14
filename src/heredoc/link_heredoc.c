/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:03:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 17:11:19 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_private.h"
#include "open_file.h"
#include "print_error.h"
#include <fcntl.h>

// Links the read here document to the standard input.
// If 'expand' is TRUE, expands the environment variables of its content.
// Returns the appropriate exit code after printing any error message.
int	link_heredoc(void)
{
	int	fd_file;
	int	err;

	fd_file = open_file(HEREDOC_FILENAME, O_RDONLY);
	if (fd_file == -1)
		return (print_err_heredoc());
	err = dup2(fd_file, STDIN_FILENO);
	if (!err)
		err = close(fd_file);
	if (err)
		return (print_err_heredoc());
	return (EXIT_SUCCESS);
}
