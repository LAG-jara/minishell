/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:45:04 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 19:53:48 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_file.h"

// Prints the corresponding error message (according to errno).
static void	err_open(char *filename)
{
	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(filename, STDERR_FILENO);
}

// Opens the file 'filename' with the given 'flags' and exits.
// If it can't be opened, prints an error message and 'errno' is set.
int	open_file(char *filename, int flags)
{
	int	fd_file;

	fd_file = open(filename, flags, 0644);
	if (fd_file == -1)
		err_open(filename);
	return (fd_file);
}
