/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:29:13 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/14 17:58:29 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

// Returns a pointer to the first character of the line containing the
// environment variable 'varname'. If 'varname' is not found returns NULL.
char	*find_var_line(char *varname, char **env)
{
	int		name_len;

	if (*varname == '$')
		varname++;
	name_len = get_name_len(varname);
	if (name_len == 0)
		return (NULL);
	while (*env)
	{
		if (ft_strncmp(*env, varname, name_len) == 0)
			return (*env);
		env++;
	}
	return (NULL);
}

// If 'str' points to the begginning of a variable name, returns its lenght.
int	get_name_len(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '$')
		i = 1;
	while (str[i] && ft_isspace(str[i]) == 0 && ft_isalnum(str[i]) == 1)
		i++;
	return (i);
}

// Returns the value of the environment variable name 'varname'.
char	*get_var(char *varname, char **env)
{
	int		name_len;
	char	*var_line;

	var_line = find_var_line(varname, env);
	if (*varname == '$')
		varname++;
	name_len = get_name_len(varname);
	if (var_line == NULL)
		return (NULL);
	return (var_line + name_len + 1);
}

// Returns a NULL-terminated array of strings containing the values of PATH.
char	**get_paths(char **env)
{
	char	*value;
	char	**paths;

	value = get_var("PATH", env);
	paths = ft_split(value, ':');
	return (paths);
}
