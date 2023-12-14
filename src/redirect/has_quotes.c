/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delim_quote_remove.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:19:49 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/14 15:23:43 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

// Returns TRUE if the null-terminated string 'word' has any ' or " character.
// Otherwise, returns FALSE.
int	has_quotes(const char *word)
{
	if (!ft_strchr(word, '"') && !ft_strchr(word, '\''))
		return (FALSE);
	return (TRUE);
}
