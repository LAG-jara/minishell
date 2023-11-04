/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:18:17 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 18:03:40 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wait_children.h"

// Waits for the children with process ID 'pid' to finish and returns its
// return value (if exited).
int	wait_children(pid_t last_child_pid)
{
	pid_t	pid;
	int		i;
	int		status;
	int		ret_status;

	i = 0;
	while (i++ < 2)						// TODO: check that '2'
	{
		pid = wait(&status);
		if (pid == last_child_pid)
			ret_status = status;
	}
	if (WIFEXITED(ret_status))
		return (WEXITSTATUS(ret_status));
	return (EXIT_FAILURE);
}
