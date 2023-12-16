/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:03:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/16 17:49:41 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_private.h"
#include "open_file.h"
#include "print_error.h"
#include <fcntl.h>

// Links the 'n'-th command's here document to the standard input.
// Returns the appropriate exit code after printing any error message.
int	link_heredoc(int n)
{
	char	*filename;
	int		fd_file;
	int		err;

	filename = heredoc_filename(n);
	fd_file = open_file(filename, O_RDONLY);
	free(filename);
	if (fd_file == -1)
		return (print_err_heredoc());
	err = dup2(fd_file, STDIN_FILENO);
	if (!err)
		err = close(fd_file);
	if (err)
		return (print_err_heredoc());
	return (EXIT_SUCCESS);
}
