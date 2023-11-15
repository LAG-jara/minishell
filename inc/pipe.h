/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:00:55 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/15 17:02:01 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include <sys/wait.h>

# define READ_END	0					// pipe's read end index
# define WRITE_END	1					// pipe's write end index

typedef struct s_pipe {
	size_t	cmds_amount;
	int		prev_fds[2];
	int		next_fds[2];
}	t_pipe;

pid_t	fork_or_die();
void	pipe_or_die(int fd_pipe[2]);
void	link_read_end(int *fd_pipe);
void	link_write_end(int *fd_pipe);
int		wait_children(pid_t pid, size_t n);

#endif