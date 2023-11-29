/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:29:13 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/29 15:49:58 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
# include "debug.h"

// Given that 'str' points to the leading '$' of a variable name, returns its 
// length excluding the '$'.
int	get_name_len(const char *str)
{
	int	i;

	if (str[0] != '$')							// TODO: remove this line
		printf("ERROR on get_name_len!!\n");	// and this one
	i = 1;
	if (str[i] && (ft_isalpha(str[i]) || str[i] == '_'))
	{
		++i;
		while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
			++i;
	}
	return (i - 1);
}

// Given that 'varname' points to the leading '$' character of a variable name,
// returns its value. If 'varname' does not exist, returns NULL.
char	*get_var(const char *varname, char **env)
{
	int		name_len;
	char	*var_line;

	var_line = find_var_line(varname, env);
	name_len = get_name_len(varname);
	if (var_line == NULL)
		return (NULL);
	return (var_line + name_len + 1);
}

// Allocates and returns a NULL-terminated array of strings containing the
// values of the colon-separated environment value 'varname'.
// If 'varname' does not exist, returns NULL.
// NOTE: 'varname' is assumed to point to the leading '$' character.
char	**get_vars(const char *varname, char **env)
{
	char	*value;
	char	**values;

	value = get_var(varname, env);
	if (!value)
		return (NULL);
	values = ft_split(value, ':');
	return (values);
}
