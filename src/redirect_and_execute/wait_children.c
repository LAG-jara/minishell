/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:18:17 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/22 12:40:06 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

// Waits for 'n' children processes to finish and returns the exit status of
// the 'last_pid' (if exited).
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
		if (WTERMSIG(ret_status) == SIGINT)
			return (130);
		if (WTERMSIG(ret_status) == SIGQUIT)
		{
			printf("Quit: 3");
			return (131);
		}
	}
	printf("\n");
	return (EXIT_FAILURE);
}
