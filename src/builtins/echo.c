/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:02:50 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/22 13:02:53 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
/*
echo [-n] [arg ...]
	Output the args, separated by spaces, followed by a newline. 
	The return status is always 0. 
	If -n is specified, the trailing newline is suppressed.
*/

void	echo_builtin(char **word, int flag)
{
	int first;

	first = 0;
	while (*word)
	{
		if (word)
			write(1, " ", 1);
		write(1, word, strlen(*word));
		first = 1;
		word++;
	}
	if (!flag)
		write(1, "\n", 1);
}