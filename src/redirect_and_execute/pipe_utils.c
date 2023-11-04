/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:52:16 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 18:28:40 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipe_utils.h"

// Creates a pipe on the 'fd_pipe' file descriptors.
// On failure, exits.
void	pipe_or_die(int fd_pipe[2])
{
	if (pipe(fd_pipe) == -1)
		exit (EXIT_FAILURE);
}

// Links the standard output to the read end of a pipe, closing the write end.
void	link_read_end(int *fd_pipe)
{
	close(fd_pipe[WRITE_END]);
	dup2(fd_pipe[READ_END], STDIN_FILENO);
	close(fd_pipe[READ_END]);
}

// Links the standard output to the write end of a pipe, closing the read end.
void	link_write_end(int *fd_pipe)
{
	close(fd_pipe[READ_END]);
	dup2(fd_pipe[WRITE_END], STDOUT_FILENO);
	close(fd_pipe[WRITE_END]);
}
