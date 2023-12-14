/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_or_die.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:52:16 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 17:50:59 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
