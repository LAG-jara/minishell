/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:18:17 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/15 17:01:50 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdlib.h>

// Waits for the children with process ID 'pid' to finish and returns its
// return value (if exited). It waits for 'n' children at most.
int	wait_children(pid_t pid, size_t n)
{
	pid_t	pid;
	int		i;
	int		status;
	int		ret_status;

	i = 0;
	while (i++ < n)
	{
		pid = wait(&status);
		if (pid == pid)
			ret_status = status;
	}
	if (WIFEXITED(ret_status))
		return (WEXITSTATUS(ret_status));
	return (EXIT_FAILURE);
}
