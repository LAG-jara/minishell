/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:13:59 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/12 18:23:48 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "basic_utils.h"

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
// 'value'. 'nxt' and 'pre' are initialized to NULL.
t_list	*lst_new(void *value, size_t size)
{
	t_list	*lstnode;

	lstnode = (t_list *)p_malloc(sizeof (t_list));
	lstnode->val = p_malloc(size);
	ft_memcpy(lstnode->val, value, size);
	lstnode->nxt = NULL;
	lstnode->pre = NULL;
	return (lstnode);
}
