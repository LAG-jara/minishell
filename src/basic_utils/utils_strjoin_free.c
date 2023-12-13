/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_strjoin_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:27:53 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/13 11:48:20 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

// Returns the length of the string 'str' (but its NULL-protected).
static size_t	p_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

// Copies the 'src' string into 'dst', ensuring NUL-termination of the string
// (but 'src' is NULL-protected).
// If the return value is >= dstsize, the output string has been truncated.
// It is the caller's responsibility to handle this.
static size_t	p_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = p_strlen(src);
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (src && src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

// Copies and concatenates the string 'src' into 'dst', taking the full size of
// 'dst' (defined by 'dstsize') and ensuring NULL-termination (but 'src' is
// NULL-protected). Returns the total length of the string it tried to create.
static size_t	p_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*dst_cpy;
	char	*src_cpy;
	size_t	dlen;
	size_t	n;

	n = dstsize;
	dst_cpy = dst;
	src_cpy = (char *)src;
	while (n-- != 0 && *dst)
		dst++;
	dlen = dst - dst_cpy;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + p_strlen(src));
	while (*src)
	{
		if (n != 1)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - src_cpy));
}

// Allocates (with malloc(3)) a new string, which is the result of the 
// concatenation of 's1' and 's2'. Finally, the original 's1' is freed and the
// new allocated string is pointed by 's1'.
void	ft_strjoin_free(char **s1, const char *s2)
{
	size_t	strsize;
	char	*str;

	strsize = p_strlen(*s1) + p_strlen(s2) + 1;
	str = (char *)p_malloc(strsize * sizeof(char));
	p_strlcpy(str, *s1, strsize);
	p_strlcat(str, s2, strsize);
	free(*s1);
	*s1 = str;
}
