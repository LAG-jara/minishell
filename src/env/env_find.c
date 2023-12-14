/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:59:27 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 20:08:39 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "basic_utils.h"

// Returns a pointer to the first character of the line containing the
// environment variable 'varname'. If 'varname' is not found returns NULL.
char	*find_var_line(const char *varname, char **env)
{
	int	name_len;

	name_len = get_name_len(varname);
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

// Returns the index of the environment variable 'varname'.
// If 'varname' is not found, returns -1.
int	find_var_index(const char *varname, char **env)
{
	int	name_len;
	int	i;

	name_len = get_name_len(varname);
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
