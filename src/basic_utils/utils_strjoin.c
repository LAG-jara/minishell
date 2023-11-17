/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:44:49 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/17 18:51:05 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

// Allocates (with malloc(3)) and returns a new string, which is the result of 
// the concatenation of ’s1’ and ’s2’.
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	strsize;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strsize = s1_len + s2_len + 1;
	str = (char *)p_malloc(strsize * sizeof(char));
	ft_strlcpy(str, s1, strsize);
	ft_strlcat(str, s2, strsize);
	return (str);
}
