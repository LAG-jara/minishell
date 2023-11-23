/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:25:26 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/23 15:49:41 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_file.h"
#include "print_error.h"
#include <stdlib.h>

# include "debug.h"

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
		print_err_filename(filename);
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
	int	ret;

	// printf("openning %s...\n", filename);
	if (append)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	fd_file = open_file(filename, flags);
	// dprintf(STDERR_FILENO, "fd_file: %d\n", fd_file);
	if (fd_file == -1)
		return (EXIT_FAILURE);
	ret = dup2(fd_file, STDOUT_FILENO);
	// dprintf(STDERR_FILENO, "ret: %d\n", ret);
	if (ret == -1)
	{
		// dprintf(STDERR_FILENO, "errorsito\n");
		print_err_filename(filename);
		return (EXIT_FAILURE);
	}
	ret = close(fd_file);
	// dprintf(STDERR_FILENO, "ret: %d\n", ret);
	if (ret == -1)
	{
		// dprintf(STDERR_FILENO, "errorsito\n");
		print_err_filename(filename);
		return (EXIT_FAILURE);
	}
	// dprintf(STDERR_FILENO, "todo OK\n");
	return (EXIT_SUCCESS);
}
