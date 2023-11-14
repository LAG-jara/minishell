/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:03:23 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/25 14:33:10 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/param.h>
#include "basic_utils.h"
#include "builtins.h"
/*
pwd
	Print the absolute pathname of the current working directory.
	The return status is 0 unless an error occurs while reading the name of the
	current directory or an invalid option is supplied.
*/
int	pwd_builtin(void)
{
	char *buffer;

	
	buffer = NULL;
	buffer = getcwd(buffer, 42);
	if (!buffer)
		return (2);
	write(1, buffer, ft_strlen(buffer));
	write(1, "\n", 1);
	free(buffer);
	return (0);
}


int	main(int ac, char **av, char **e)
{
	// char **env = arrstr_dup(e);
	ac += 0;
	av += 0;
	e += 0;
	// char *pre_toks[] = \
	// { "hola", "final", NULL};

	// t_list	**cmds;
	// cmds = parse(pre_toks);
	// if (cmds)
	// 	print_cmds(cmds);

	pwd_builtin();
	//lst_clear(cmds, tok_del);
	//free(cmds);
}