/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:56:50 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/14 18:59:09 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_utils.h"
#include "quote_utils.h"
#include "boolean.h"

// Returns TRUE if 'str' is a valid word, FALSE otherwise.
int	is_word(const char *str)
{
	int	q_stat;

	q_stat = UNQUOTED;
	while (*str)
	{
		if (q_stat == UNQUOTED && is_metachr(*str))
			return (FALSE);
		quote_stat(&q_stat, *str);
		++str;
	}
	if (q_stat != UNQUOTED)
		return (FALSE);
	return (TRUE);
}
