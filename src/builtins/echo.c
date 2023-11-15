/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:02:50 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/15 14:12:03 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include "definitions.h"
#include <unistd.h>
#include <stdio.h>

static int is_flag(char *word)
{
	int i;

	i = 0;
	if (word[i++] != '-')
		return (FALSE);
	while (word[i] && word[i] == 'n')
		++i;
	if (word[i])
		return (FALSE);
	return(TRUE);
}

static int get_flag(char **word)
{
	int idx;

	idx = 0;
	while (is_flag(word[idx]))
		++idx;
	return (idx);
}

/*
echo [-n] [arg ...]
	Output the args, separated by spaces, followed by a newline. 
	The return status is always 0. 
	If -n is specified, the trailing newline is suppressed.
*/
int	echo_builtin(char **word)
{
	int first;
	int flag;

	first = 0;
	flag = get_flag(word);
	word += flag;
	while (*word)
	{
		if (first)
			printf(" ");
		printf("%s", *word);
		first = 1;
		word++;
	}
	if (!flag)
		printf("\n");
	return (0);
}

// # include "debug.h"
// # include "builtins.h"

// int	main(int ac, char **av)
// {
// 	ac += 0;
// 	av += 0;
// 	echo_builtin(++av);
// }