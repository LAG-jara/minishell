/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:19:42 by Guillem L         #+#    #+#             */
/*   Updated: 2023/10/15 16:18:42 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Counts the amount of substrings resulting from splitting s using the 
// char c as a delimeter.
static size_t	count_substr(char *s, char c)
{
	size_t	count;
	int		flag;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (flag == 0)
			{
				flag = 1;
				count++;
			}
		}
		else
			flag = 0;
		s++;
	}
	return (count);
}

// Allocates and returns the first substring on s using c as a delimeter.
// The string pointed by s is now pointing just after the popped substring.
static char	*pop_str(char **s, char c)
{
	char	*substr;
	char	*str;
	size_t	strlen;

	str = *s;
	strlen = 0;
	while (*str && *str == c)
		str++;
	while (str[strlen] && str[strlen] != c)
		strlen++;
	substr = malloc((strlen + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, str, strlen + 1);
	*s = str + strlen;
	return (substr);
}

// Fees allocated space in a NULL-terminated array. Returns NULL.
static void	*freearr(char **arr)
{
	char	**arrcpy;

	arrcpy = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(arrcpy);
	return (NULL);
}

// Allocates (with malloc(3)) and returns an array of strings obtained by 
// splitting ’s’ using the character ’c’ as a delimiter. The array must end 
// with a NULL pointer.
char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	substr_count;
	char	*str;
	size_t	count;

	if (!s)
		return (NULL);
	count = 0;
	str = (char *) s;
	substr_count = count_substr(str, c);
	arr = malloc((substr_count + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (count < substr_count)
	{
		arr[count] = pop_str(&str, c);
		if (arr[count++] == NULL)
			return (freearr(arr));
	}
	arr[count] = NULL;
	return (arr);
}
