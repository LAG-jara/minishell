/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:59:27 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/29 15:50:41 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

// Returns a pointer to the first character of the line containing the
// environment variable 'varname'. If 'varname' is not found returns NULL.
// NOTE: 'varname' is assumed to point to the leading '$' character.
char	*find_var_line(const char *varname, char **env)
{
	int	name_len;

	name_len = get_name_len(varname);
	if (name_len == 0)
		return (NULL);
	++varname;
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
// NOTE: 'varname' is assumed to point to the leading '$' character.
int	find_var_index(const char *varname, char **env)
{
	int	name_len;
	int	i;

	name_len = get_name_len(varname);
	if (name_len == 0)
		return (-1);
	++varname;
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], varname, name_len) == 0 && \
			env[i][name_len] == '=')
			return (i);
	}
	return (-1);
}
