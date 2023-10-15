/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:29:05 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/15 13:41:24 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "env.h"

// Allocates and returns a string consisting of 'varname' + "=" + 'value'.
static char	*join_varline(char *varname, char *value)
{
	char	*varline;
	size_t	varline_len;

	varline_len = ft_strlen(varname) + ft_strlen(value) + 2;
	varline = (char *) malloc(sizeof(char) * varline_len);
	while (*varname)
		*varline++ = *varname++;
	*varline++ = '=';
	while (*value)
		*varline++ = *value++;
	*varline = '\0';
	return (varline);
}

// Returns a copy of the 'env' NULL-terminated array with the environment
// variable 'varname' added at the end with the value 'value'.
char	**add_env_var(char *varname, char *value, char **env)
{
	char	**new_env;
	char	*varline;

	varline = join_varline(varname, value);
	new_env = add_strarr2(varline, env);
}

// Sets the environment variable 'varname' to 'value', creating it if needed.
void	set_env_var(char *varname, char *value, char ***env)
{
	char	*var_line;

	var_line = find_var_line(varname, *env);
	if (var_line == NULL)
	{
		*env = add_env_var(varname, value, *env);
	}
	
}
