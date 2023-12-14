/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirectionchr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:56:50 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/14 20:12:39 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boolean.h"

// Returns TRUE if 'c' is the char '<' or '>', returns FALSE otherwise.
int	is_redirectionchr(int c)
{
	if (c == '<' || c == '>')
		return (TRUE);
	return (FALSE);
}
