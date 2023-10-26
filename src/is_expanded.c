/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_expanded.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:32:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 17:33:08 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_expanded.h"

// Returns TRUE or FALSE whether 'index' is in one of the 'expanded' ranges.
// 'expanded' includes indexes in ascending order so even indexes defines a
// range start (inclusive) and odd indexes defines ends (exclusive).
int	is_expanded(int index, int *expanded)
{
	int	i;

	if (!expanded)
		return (FALSE);
	i = -1;
	while (expanded[++i] != -1)
	{
		if (index < expanded[i])
			return (FALSE);
		if (index == expanded[i])
			return (TRUE);
		if (index > expanded[i] && index < expanded[i + 1])
			return (TRUE);
		++i;
	}
	return (FALSE);
}
