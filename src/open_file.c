/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:45:04 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 17:09:16 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_file_private.h"
#include "print_error.h"
#include <fcntl.h>

// Opens the file 'filename' with the 'flags' and returns its file descriptor.
// On failure, prints an error message and returns -1 (setting errno).
int	open_file(const char *filename, int flags)
{
	int	fd_file;

	fd_file = open(filename, flags, OPEN_FILE_MODE);
	if (fd_file == -1)
		print_err_filename(filename);
	return (fd_file);
}
