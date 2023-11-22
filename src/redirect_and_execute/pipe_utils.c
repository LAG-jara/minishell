/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:52:16 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/22 12:52:55 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"
#include "stdlib.h"
#include "unistd.h"

// Creates a new process (using fork()) returning 0 to the child process and the
// pid of the child to the parent.
// On failure, prints an error message (TODO) and exits.
pid_t	fork_or_die(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit (EXIT_FAILURE);
	return (pid);
}

// Creates a pipe and allocates a pair of file descriptors at 'fd_pipe'.
// On failure, prints an error message (TODO) and exits.
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
