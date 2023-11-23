/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:04:10 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/03 19:57:05 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "definitions.h"

/*
exit 
	Prints “exit” followed by a newline before closing the shell. 
	The exit status is that of the last command executed.
*/
void	exit_builtin(char **args, int exit_status)
{
	long long	exit_s =0;

	args+=0;
	exit_status+=0;
	write(1, "exit\n", 5);
	// if (*args == FALSE)
	// 	exit(exit_status);	// TODO: Last command executed?????
	// if (is_longlong(args[0]) == FALSE)
	// 	// Error de numeric argument required hace salir de bash. exit_status 255
	// if (args[1] != NULL)
	// 	// Comprueba que no hayan más argumentos.
	// 	// Error de too many arguments y no sale. exit_status de EXIT_FALIURE
	// exit_s = ft_atoll(args[0]);
	exit(exit_s % 256);
}

// # include "debug.h"
// # include "arrstr.h"
// # include "parse_tokens.h"
// int	main(int ac, char **av, char **e)
// {
// 	char **env = arrstr_dup(e);
// 	ac += 0;
// 	av += 0;
// 	env += 0;
// 	char *pre_toks[] = \
// 	{ "hola", "final", NULL};

// 	t_list	**cmds;
// 	cmds = parse(pre_toks);
// 	if (cmds)
// 		print_cmds(cmds);

// 	//env_free(env);
// 	lst_clear(cmds, tok_del);
// 	free(cmds);
// 	exit_builtin();
// }