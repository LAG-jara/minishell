/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:55:53 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:37:33 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "print_error.h"
#include "arrstr.h"

int	main(int ac, char **av, char **e)
{
	char	**env;

	if (ac != 1)
		return (print_err_argc());
	av += 0;
	env = arrstr_dup(e);
	minish_loop(env);
	return (EXIT_SUCCESS);
}
