/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:29:13 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/01 09:32:14 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

// DEPRECATED : Falta '_'

// Given that 'str' points to the begginning of a variable name, returns its 
// length ignoring the leading '$' (if any).
// int	get_name_len(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (str[i] == '$')
// 		i = 1;
// 	if (str[i] && ft_isalpha(str[i]))
// 	{
// 		++i;
// 		while (str[i] && ft_isalnum(str[i]))
// 			++i;
// 	}
// 	return (i);
// }

// Returns the value of the environment variable name 'varname'.
// If 'varname' does not exist, returns NULL.
char	*get_var(char *varname, char **env)
{
	int		name_len;
	char	*var_line;

	var_line = find_var_line(varname, env);
	if (*varname == '$')
		++varname;
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
