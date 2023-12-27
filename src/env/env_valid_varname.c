/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_valid_varname.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:50:08 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/20 13:01:01 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

// Checks and returns TRUE if the given 'word' us a valid variable name.
// A valid name consists only of alphanumeric characters and underscores, and
// begins with an alphabetic character or an underscore.
int	env_valid_varname(char *word)
{
	if (!word || !*word)
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
