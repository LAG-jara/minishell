/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_substr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:58:37 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/29 16:03:39 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

// Allocates and returns a substring from the string 's'.
// The substring begins at index 'start' and is of maximum size 'len'.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	slen;
	size_t	strlen;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	while (start + i <= slen && s[start + i] && i < len)
		++i;
	strlen = i;
	str = (char *)p_malloc(sizeof(char) * (strlen + 1));
	i = 0;
	while (i < strlen)
	{
		str[i] = s[start + i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
