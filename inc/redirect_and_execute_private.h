/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_and_execute_private.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:36:12 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/18 19:01:35 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_AND_EXECUTE_PRIVATE_H
# define REDIRECT_AND_EXECUTE_PRIVATE_H

# include "list.h"
# include <unistd.h>

# define READ_END		0				// pipe's read end index
# define WRITE_END		1				// pipe's write end index

typedef struct s_pipe
{
	int	cmds_amount;
	int	prev_fds[2];
	int	next_fds[2];
	int	i;
}	t_pipe;

int		read_all_heredocs(t_list **cmds, int cmds_amount, char **env);
pid_t	fork_or_die(void);
void	pipe_or_die(int fd_pipe[2]);
void	link_read_end(int *fd_pipe);
void	link_write_end(int *fd_pipe);
int		wait_children(pid_t pid, size_t n);

#endif
