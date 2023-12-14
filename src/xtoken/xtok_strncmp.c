/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtok_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:10:03 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 20:07:10 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"
#include "basic_utils.h"

// Returns an integer greater than, equal to, or less than 0, according as the 
// string the value of 'xtok' is greater than, equal to, or less than 'str',
// comparing not more than 'n' characters.
int	xtok_strncmp(t_xtoken *xtok, const char *str, size_t n)
{
	int		ret;
	char	*xtok_val;

	xtok_val = xclst_to_str(xtok->val);
	ret = ft_strncmp(xtok_val, str, n);
	free(xtok_val);
	return (ret);
}
