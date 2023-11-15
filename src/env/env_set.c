/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:29:05 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 12:18:16 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

// Allocates and returns a string consisting of 'varname' + "=" + 'value'.
static char	*join_varline(const char *varname, const char *value)
{
	char	*varline;
	size_t	varline_len;
	char	*varline_cpy;

	varline_len = ft_strlen(varname) + ft_strlen(value) + 2;
	varline = (char *)p_malloc(sizeof(char) * varline_len);
	varline_cpy = varline;
	while (*varname)
		*varline++ = *varname++;
	*varline++ = '=';
	while (*value)
		*varline++ = *value++;
	*varline = '\0';
	return (varline_cpy);
}

// Sets the environment variable 'varname' to 'value', creating it if needed.
void	set_env_var(const char *varname, const char *value, char ***env)
{
	int		var_index;
	char	*varline;

	varline = join_varline(varname, value);
	var_index = find_var_index(varname, (const char **)*env);
	if (var_index == -1)
		*env = arrstr_add(*env, varline);
	else
		*env = arrstr_set(*env, varline, var_index);
}

// Removes the environment variable 'varname'.
void	rm_env_var(const char *varname, char ***env)
{
	int		var_index;

	var_index = find_var_index(varname, (const char **)*env);
	if (var_index >= 0)
		*env = arrstr_rm(*env, var_index);
}

// #include "debug.h"
// int	main(int ac, char **av, char **e)
// {
// 	char **env = arrstr_dup(e);

// 	// char *str = get_var("USER", env);
// 	// printf("Result: %s\n", str);

// 	set_env_var("USER", "Albert Lajara", &env);
// 	print_arrstr(env);

// 	// rm_env_var("HOME", &env);
// 	// print_arrstr(env);

// 	return (0);
// }
