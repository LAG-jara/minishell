/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_input_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:25:26 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 17:38:00 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_file.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// Opens the file 'filename' and links it to the standard input.
// Returns the appropriate exit code after printing any error message.
int	link_input_file(const char *filename)
{
	int	fd_file;
	int	ret;

	fd_file = open_file(filename, O_RDONLY);
	if (fd_file == -1)
		return (EXIT_FAILURE);
	ret = dup2(fd_file, STDIN_FILENO);
	if (ret == -1)
		return (EXIT_FAILURE);
	ret = close(fd_file);
	if (ret == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
