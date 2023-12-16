/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:18:17 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/16 15:31:32 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "basic_utils.h"

// Waits for 'n' (n > 0) children processes to finish and returns the 
// exit status of the 'last_pid' (if exited).
int	wait_children(pid_t last_pid, size_t n)
{
	pid_t	pid;
	size_t	i;
	int		status;
	int		ret_status;

	i = 0;
	while (i++ < n)
	{
		pid = wait(&status);
		if (pid == last_pid)
			ret_status = status;
	}
	if (WIFEXITED(ret_status))
		return (WEXITSTATUS(ret_status));
	else if (WIFSIGNALED(ret_status))
	{
		if (WTERMSIG(ret_status) == SIGQUIT)
			ft_putstr_fd("Quit: 3", STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		return (WTERMSIG(ret_status) + 128);
	}
	return (EXIT_FAILURE);
}
