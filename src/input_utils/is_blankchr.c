/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_blankchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:56:50 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/14 20:12:45 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_utils.h"
#include "boolean.h"

// Returns TRUE if 'c' is the char <space> or <tab>, returns FALSE otherwise.
int	is_blankchr(int c)
{
	if (c == ' ' || c == '\t')
		return (TRUE);
	return (FALSE);
}
