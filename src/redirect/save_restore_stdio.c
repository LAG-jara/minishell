/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_restore_stdio.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:25:26 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 17:40:14 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect.h"
#include <unistd.h>
#include <fcntl.h>

// If 'mode' = SAVE: Saves the standard input and output.
// If 'mode' = RESTORE: Restores the previously saved standard input and output.
void	save_restore_stdio(int std_in, int std_out, int mode)
{
	static int	saved_stdin;
	static int	saved_stdout;

	if (mode == SAVE)
	{
		saved_stdin = dup(std_in);
		saved_stdout = dup(std_out);
	}
	if (mode == RESTORE)
	{
		dup2(saved_stdin, std_in);
		close(saved_stdin);
		dup2(saved_stdout, std_out);
		close(saved_stdout);
	}
}
