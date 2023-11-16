/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:25:26 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/16 15:35:06 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_file.h"
#include "stdlib.h"

// Opens the file 'filename' and links it to the standard input.
// Returns the appropriate exit code after printing any error message.
int	link_input_file(const char *filename)
{
	int	fd_file;
	int	err;

	fd_file = open_file(filename, O_RDONLY);
	if (fd_file == -1)
		return (EXIT_FAILURE);
	err = dup2(fd_file, STDIN_FILENO);
	if (!err)
		err = close(fd_file);
	if (err)
	{
		print_errno_msg(filename);
		return (EXIT_FAILURE);
	}
	return (0);
}

// Opens the file 'filename' and links it to the standard output.
// If 'append' is not zero, it opens the file with the O_APPEND flag.
// Returns the appropriate exit code after printing any error message.
int	link_output_file(const char *filename, int append)
{
	int	fd_file;
	int	flags;
	int	err;

	if (append)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	fd_file = open_file(filename, flags);
	if (fd_file == -1)
		return (EXIT_FAILURE);
	err = dup2(fd_file, STDOUT_FILENO);
	if (!err)
		err = close(fd_file);
	if (err)
	{
		print_err_filename(filename);
		return (EXIT_FAILURE);
	}
	return (0);
}
