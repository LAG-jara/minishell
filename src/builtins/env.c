/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:04:02 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/22 13:04:03 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
/*
env
	Prints the current environment.
*/

void	printvar(char *var)
{
	while (*var)
	{
		write(stdout, var, 1);
		var++;
	}
	write(stdout, "\n", 1);
}

void	env_builtin(char **env)
{
	while (*env)
	{
		if (ft_strchr(*env, '='))
			printvar(*env)
		env++;
	}
}