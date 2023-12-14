/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:40:39 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 18:59:09 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boolean.h"

// Returns TRUE if 'c' is a white-space character, FALSE otherwise.
int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (TRUE);
	return (FALSE);
}

// Returns TRUE if 'c' is an alphabetic character, FALSE otherwise.
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (TRUE);
	return (FALSE);
}

// Returns TRUE if 'c' is a decimal digit character, FALSE otherwise.
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

// Returns TRUE if 'c' is an alphanumeric character, FALSE otherwise.
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (TRUE);
	return (FALSE);
}
