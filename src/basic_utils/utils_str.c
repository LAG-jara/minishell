/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:08:42 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/22 16:08:16 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

// Retuns a pointer to the first occurrence of 'c' in str.
// If there aren't, returns NULL.
char	*ft_strchr(const char *str, char c)
{
	while (str && *str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

// Returns an integer greater than, equal to, or less than 0, according as the 
// string 's1' is greater than, equal to, or less than the string 's2', 
// comparing not more than 'n' characters.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0 || s1 == s2)
		return (0);
	i = 0;
	while (i < (n - 1) && s1[i] && s2[i] && s1[i] == s2[i])
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// Returns the length of the string 'str'.
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

// Copies the 'src' string into 'dst', ensuring NUL-termination of the string.
// If the return value is >= dstsize, the output string has been truncated.
// It is the caller's responsibility to handle this.
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (srclen);
}

// Allocates and returns a copy of the given string.
// Exits properly if malloc fails.
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = (char *)p_malloc((len + 1) * sizeof(char));
	ft_strlcpy(s2, s1, len + 1);
	return (s2);
}
