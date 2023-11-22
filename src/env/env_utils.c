/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:50:08 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/03 19:57:49 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrstr.h"
#include "definitions.h"

// Checks and returns TRUE if the given 'word' us a valid variable name.
// A valid name consists only of alphanumeric characters and underscores, and
// begins with an alphabetic character or an underscore.
int	valid_varname(char *word)
{
	if (!word)
		return (FALSE);
	if (*word == '_' || ft_isalpha(*word))
	{
		++word;
		while (*word == '_' || ft_isalnum(*word))
			++word;
	}
	if (!*word)
		return (TRUE);
	return (FALSE);
}

// Frees the NULL-terminated array of strings 'env'.
void	env_free(char **env)
{
	arrstr_free(env);
}

// Check if the string has a proper name for an environment variable before
// any '=' if exists. Returns the valid varname or NULL if invalid.
char	*get_varname(char *str)
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
	if (!str || !valid_varname(varname))
	{
		free(varname);
		return (NULL);
	}
	return (varname);
}
