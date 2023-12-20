/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_rm_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:29:05 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/20 13:00:27 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_private.h"
#include "arrstr.h"

// Removes the environment variable 'varname'.
void	env_rm_var(const char *varname, char ***env)
{
	int		var_index;

	var_index = env_find_var_index(varname, *env);
	if (var_index >= 0)
		*env = arrstr_rm(*env, var_index);
}
