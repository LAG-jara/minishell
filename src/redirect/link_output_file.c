/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_output_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:25:26 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 17:38:38 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_file.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// Opens the file 'filename' and links it to the standard output.
// If 'append' is not zero, it opens the file with the O_APPEND flag.
// Returns the appropriate exit code after printing any error message.
int	link_output_file(const char *filename, int append)
{
	int	fd_file;
	int	flags;
	int	ret;

	if (append)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	fd_file = open_file(filename, flags);
	if (fd_file == -1)
		return (EXIT_FAILURE);
	ret = dup2(fd_file, STDOUT_FILENO);
	if (ret == -1)
		return (EXIT_FAILURE);
	ret = close(fd_file);
	if (ret == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
