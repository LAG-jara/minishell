/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:29:13 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/15 14:12:28 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

// Given that 'str' points to the begginning of a variable name, returns its 
// length ignoring the leading '$' (if any).
int	get_name_len(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '$')
		i = 1;
	if (str[i] && (ft_isalpha(str[i]) || str[i] == '_'))
	{
		++i;
		while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
			++i;
	}
	return (i);
}

// Returns the value of the environment variable name 'varname'.
// If 'varname' does not exist, returns NULL.
char	*get_var(const char *varname, char **env)
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

// Returns a NULL-terminated array of strings containing the values of the
// colon-separated environment value 'varname'.
char	**get_vars(const char *varname, char **env)
{
	char	*value;
	char	**values;

	value = get_var(varname, env);
	values = ft_split(value, ':');
	return (values);
}
