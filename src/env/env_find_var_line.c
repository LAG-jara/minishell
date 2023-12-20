/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find_var_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:59:27 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/20 12:55:42 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "basic_utils.h"

// Returns a pointer to the first character of the line containing the
// environment variable 'varname'. If 'varname' is not found returns NULL.
char	*env_find_var_line(const char *varname, char **env)
{
	int	name_len;

	name_len = env_name_len(varname);
	if (name_len == 0)
		return (NULL);
	while (*env)
	{
		if (!ft_strncmp(*env, varname, name_len)
			&& (*env)[name_len] && (*env)[name_len] == '=')
			return ((char *)*env);
		++env;
	}
	return (NULL);
}
