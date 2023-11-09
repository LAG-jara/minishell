/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:00:55 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/09 18:31:22 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_UTILS_H
# define PIPE_UTILS_H

# include "open_file.h"

# define READ_END	0					// pipe's read end index
# define WRITE_END	1					// pipe's write end index

pid_t	fork_or_die();
void	pipe_or_die(int fd_pipe[2]);
void	link_read_end(int *fd_pipe);
void	link_write_end(int *fd_pipe);

#endif