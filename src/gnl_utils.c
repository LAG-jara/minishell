/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:33:47 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/19 10:39:39 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	gnl_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

static size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = gnl_strlen(src);
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

static size_t	gnl_strlcat(char *dst, const char *src, size_t dstsize)
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
		return (dlen + gnl_strlen(src));
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

// Allocates and returns a new string, which is the result of the concatenation
// of ’s1’ and ’s2’. Finally, 's1' is freed.
// Exits properly if memory allocation fails.
char	*gnl_strjoin_free(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	strsize;
	char	*str;

	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	strsize = s1_len + s2_len + 1;
	str = malloc(strsize * sizeof(char));
	if (str == NULL)
		exit(EXIT_FAILURE);
	gnl_strlcpy(str, s1, strsize);
	gnl_strlcat(str, s2, strsize);
	free(s1);
	return (str);
}

// Allocates (with malloc(3)) and returns a substring from the string ’s’.
// The substring begins at index ’start’ and is of maximum size ’len’.
// Exits properly if memory allocation fails.
char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	slen;
	size_t	strlen;

	if (!s)
		return (NULL);
	i = 0;
	slen = gnl_strlen(s);
	while (start + i <= slen && s[start + i] && i < len)
		i++;
	strlen = i;
	str = (char *) malloc(sizeof(char) * (strlen + 1));
	if (!str)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < strlen)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
