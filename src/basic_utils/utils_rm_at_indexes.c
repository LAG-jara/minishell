/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rm_at_indexes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:38:18 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 12:16:36 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include "definitions.h"
#include "arrint_utils.h"

// Returns TRUE if 'idx' is included in the 'to_delete' array (terminated by -1)
static int	is_idx_to_delete(int idx, int *to_delete)
{
	while (*to_delete != -1)
	{
		if (*to_delete == idx)
			return (TRUE);
		++to_delete;
	}
	return (FALSE);
}

// Allocates and returns a copy of 'str' after removing the characters at 
// the 'to_delete' indexes.
char	*rm_at_indexes(char *str, int *to_delete)
{
	char	*new_str;
	int		old_len;
	int		new_len;

	old_len = ft_strlen(str);
	new_len = old_len - arrint_get_size(to_delete);
	new_str = (char *) p_malloc(sizeof(char) * (new_len + 1));
	new_str[new_len] = '\0';
	while (--old_len >= 0)
	{
		if (!is_idx_to_delete(old_len, to_delete) && --new_len >= 0)
			new_str[new_len] = str[old_len];
	}
	return (new_str);
}
