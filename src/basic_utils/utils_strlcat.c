/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_strlcat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:47:05 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/13 11:40:33 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

// Copies and concatenates the string 'src' into 'dst', taking the full size of
// 'dst' (defined by 'dstsize') and ensuring NULL-termination.
// Returns the total length of the string it tried to create.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*dst_cpy;
	char	*src_cpy;
	size_t	dlen;
	size_t	n;

	n = dstsize;
	dst_cpy = dst;
	src_cpy = (char *)src;
	while (n-- != 0 && *dst)
		++dst;
	dlen = dst - dst_cpy;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src));
	while (*src)
	{
		if (n != 1)
		{
			*dst++ = *src;
			--n;
		}
		++src;
	}
	*dst = '\0';
	return (dlen + (src - src_cpy));
}
