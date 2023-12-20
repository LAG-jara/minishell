/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find_var_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:59:27 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/20 12:55:42 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "basic_utils.h"

// Returns the index of the environment variable 'varname'.
// If 'varname' is not found, returns -1.
int	env_find_var_index(const char *varname, char **env)
{
	int	name_len;
	int	i;

	name_len = env_name_len(varname);
	if (name_len == 0)
		return (-1);
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], varname, name_len) == 0 && \
			env[i][name_len] == '=')
			return (i);
	}
	return (-1);
}
