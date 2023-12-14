/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xclst_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:14:08 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 16:20:59 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include "xchar.h"

// Allocates and returns a string representing the given list of xchars 'xclst'.
char	*xclst_to_str(t_list *xclst)
{
	char	*str;
	size_t	str_len;
	t_xchar	xc;
	int		i;

	str_len = lst_size(xclst);
	str = (char *)p_malloc(sizeof(char) * (str_len + 1));
	i = -1;
	while (xclst && xclst->val)
	{
		xc = *(t_xchar *)(xclst->val);
		str[++i] = xc.c;
		xclst = xclst->nxt;
	}
	str[i + 1] = '\0';
	return (str);
}
