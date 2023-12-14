/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_write_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:52:16 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 17:58:08 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_and_execute_private.h"
#include "stdlib.h"
#include "unistd.h"

// Links the standard output to the write end of a pipe, closing the read end.
void	link_write_end(int *fd_pipe)
{
	close(fd_pipe[READ_END]);
	dup2(fd_pipe[WRITE_END], STDOUT_FILENO);
	close(fd_pipe[WRITE_END]);
}
