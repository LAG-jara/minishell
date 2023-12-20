/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:04:02 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/14 18:56:23 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include <unistd.h>

// Lists the enviroment variables with its values. Returns 0
int	env_builtin(char **env)
{
	while (*env)
	{
		if (ft_strchr(*env, '='))
			ft_putendl_fd(*env, STDOUT_FILENO);
		++env;
	}
	return (0);
}
