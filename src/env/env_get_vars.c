/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:29:13 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/20 12:58:09 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "basic_utils.h"

// Allocates and returns a NULL-terminated array of strings containing the
// values of the colon-separated environment value 'varname'.
// If 'varname' does not exist, returns NULL.
char	**env_get_vars(const char *varname, char **env)
{
	char	*value;
	char	**values;

	value = env_get_var(varname, env);
	if (!value)
		return (NULL);
	values = ft_split(value, ':');
	return (values);
}
