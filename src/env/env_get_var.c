/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:29:13 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/20 12:58:31 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "env_private.h"
#include <stdlib.h>

// Given that 'varname' points to the first character of a variable name,
// returns its value. If 'varname' does not exist, returns NULL.
char	*env_get_var(const char *varname, char **env)
{
	int		name_len;
	char	*var_line;

	var_line = env_find_var_line(varname, env);
	name_len = env_name_len(varname);
	if (var_line == NULL)
		return (NULL);
	return (var_line + name_len + 1);
}
