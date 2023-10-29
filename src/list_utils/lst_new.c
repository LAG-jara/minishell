/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:13:59 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/29 19:04:40 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"
# include "basic_utils.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstcpy;
	unsigned char	*srccpy;

	if (dst == NULL && src == NULL)
		return (dst);
	dstcpy = (unsigned char *) dst;
	srccpy = (unsigned char *) src;
	while (n-- > 0)
		*dstcpy++ = *srccpy++;
	return (dst);
}

// Allocates (with malloc(3)) and returns a new node.
// The member variable 'val' is initialized with the value of the parameter
// 'value'. The variables 'nxt' and 'pre' is initialized to NULL.
t_lst	*lst_new(void *value, size_t size)
{
	t_lst	*lstnode;

	lstnode = (t_lst *) p_malloc(sizeof (t_lst));
	lstnode->val = p_malloc(size);
	ft_memcpy(lstnode->val, value, size);
	lstnode->nxt = NULL;
	lstnode->pre = NULL;
	return (lstnode);
}