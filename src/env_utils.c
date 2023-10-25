/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:50:08 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/25 14:39:41 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <basic_utils.h>

// Checks if all the string follows the i
int	valid_varname(char *word)
{
	if (!word)
		return (0);
	if (*word == '_' || ft_isalpha(*word))
	{
		while (*word == '_' || ft_isalnum(*word))
			++word;
	}
	if (!*word)
		return (1);
	return (0);
}

char	*get_varname(char *str)
{
	int		len;
	char	*varname;

	if (!str)
		return (NULL);
	len = ft_strlen(str) - ft_strlen(ft_strchr(str, '='));
	varname = ft_strdup(str);
	varname[len] = '\0'; 
	if (!str || !valid_varname(varname))
	{
		free (varname);
		return (NULL);
	}
	return (varname);
}