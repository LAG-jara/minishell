/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:29:05 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/20 14:09:33 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_private.h"
#include "basic_utils.h"
#include "arrstr.h"

// Allocates and returns a string consisting of 'varname' + "=" + 'value'.
static char	*join_varline(const char *varname, const char *value)
{
	char	*varline;
	size_t	varline_len;
	int		i;

	varline_len = ft_strlen(varname) + ft_strlen(value) + 1;
	varline = (char *)p_malloc(sizeof(char) * (varline_len + 1));
	i = 0;
	while (*varname)
		varline[i++] = *varname++;
	varline[i++] = '=';
	while (*value)
		varline[i++] = *value++;
	varline[i] = '\0';
	return (varline);
}

// Sets the environment variable 'varname' to 'value', creating it if needed.
void	env_set_var(const char *varname, const char *value, char ***env)
{
	int		var_index;
	char	*varline;

	varline = join_varline(varname, value);
	var_index = env_find_var_index(varname, (char **)*env);
	if (var_index == -1)
		*env = arrstr_add(*env, varline);
	else
		*env = arrstr_set(*env, varline, var_index);
	free(varline);
}
