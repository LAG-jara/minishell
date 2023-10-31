/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xclst_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:14:08 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/31 16:09:31 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Allocates and returns a string representing the given list of xchars 'xclst'.
char	*xclst_to_str(t_list *xclst)
{
	char	*str;
	size_t	str_len;
	int		i;

	str_len = lst_size(xclst);
	str = (char *)p_malloc(sizeof(char) * (str_len + 1));
	i = -1;
	while (xclst && xclst->val)
	{
		str[++i] = *(char *)(xclst->val);
		xclst = xclst->nxt;
	}
	str[i + 1] = '\0';
	return (str);
}
