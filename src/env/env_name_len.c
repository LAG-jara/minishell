/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_name_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:29:13 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/20 12:58:53 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

// Given that 'str' points to the first character of a variable name,
// returns its length.
int	env_name_len(const char *str)
{
	int	i;

	i = 0;
	if (str[i] && (ft_isalpha(str[i]) || str[i] == '_'))
	{
		++i;
		while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
			++i;
	}
	return (i);
}
