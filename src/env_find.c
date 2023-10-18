/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:59:27 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/18 19:42:30 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

// Returns a pointer to the first character of the line containing the
// environment variable 'varname'. If 'varname' is not found returns NULL.
char	*find_var_line(char *varname, char **env)
{
	int	name_len;

	if (*varname == '$')
		++varname;
	name_len = get_name_len(varname);
	if (name_len == 0)
		return (NULL);
	while (*env)
	{
		if (ft_strncmp(*env, varname, name_len) == 0
			&& (*env)[name_len] && (*env)[name_len] == '=')
			return (*env);
		++env;
	}
	return (NULL);
}

// Returns the index of the environment variable 'varname'.
// If 'varname' is not found, returns -1.
int	find_var_index(char *varname, char **env)
{
	int	name_len;
	int	i;

	if (*varname == '$')
		++varname;
	name_len = get_name_len(varname);
	if (name_len == 0)
		return (-1);
	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], varname, name_len) == 0)
			return (i);
	}
	return (-1);
}
