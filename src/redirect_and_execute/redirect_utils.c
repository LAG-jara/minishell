/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:25:26 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 19:55:17 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_file.h"

// Opens the file 'filename' and links it to the standard input.
// Returns 0 on success, and the appropriate exit code on failure.
int	link_input_file(char *filename)
{
	int	fd_file;

	fd_file = open_file(filename, O_RDONLY);
	if (fd_file == -1)
		return (errno);				// TODO: return appropriate exit code
	dup2(fd_file, STDIN_FILENO);	// TODO: return appropriate exit code
	close(fd_file);					// TODO: return appropriate exit code
	return (0);
}

// Opens the file 'filename' and links it to the standard output.
// If 'append' is not zero, it opens the file with the O_APPEND flag.
// Returns 0 on success, and the appropriate exit code on failure.
int	link_output_file(char *filename, int append)
{
	int	fd_file;
	int	flags;

	if (append)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	fd_file = open_file(filename, flags);
	if (fd_file == -1)
		return (errno);				// TODO: return appropriate exit code
	dup2(fd_file, STDOUT_FILENO);	// TODO: return appropriate exit code
	close(fd_file);					// TODO: return appropriate exit code
	return (0);
}
