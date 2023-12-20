/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_varname.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:50:08 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/20 14:11:37 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "basic_utils.h"

// Check if the string has a proper name for an environment variable before
// any '=' if exists.
// Allocates and returns the valid varname or NULL if invalid.
char	*env_get_varname(const char *str)
{
	int		len;
	char	*varname;

	if (!str)
		return (NULL);
	if (!ft_strchr(str, '='))
		len = ft_strlen(str);
	else
		len = ft_strlen(str) - ft_strlen(ft_strchr(str, '='));
	varname = ft_strdup(str);
	varname[len] = '\0';
	if (!env_valid_varname(varname))
	{
		free(varname);
		return (NULL);
	}
	return (varname);
}
