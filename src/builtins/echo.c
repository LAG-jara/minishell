/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:02:50 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/20 17:20:45 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include <unistd.h>
#include <stdio.h>

static int	is_flag(char *word)
{
	int	i;

	i = 0;
	if (word[i++] != '-')
		return (FALSE);
	while (word[i] && word[i] == 'n')
		++i;
	if (word[i])
		return (FALSE);
	return (TRUE);
}

static int	get_flag(char **args)
{
	int	idx;

	idx = 0;
	while (args[idx] && is_flag(args[idx]))
		++idx;
	return (idx);
}

// Output the 'args', separated by spaces, followed by a newline. 
// The return status is always 0. 
// If -n is specified, the trailing newline is suppressed.
int	echo_builtin(char **args)
{
	int	first;
	int	flag;

	first = 0;
	flag = get_flag(args);
	args += flag;
	while (*args)
	{
		if (first)
			printf(" ");
		printf("%s", *args);
		first = 1;
		args++;
	}
	if (!flag)
		printf("\n");
	return (0);
}
