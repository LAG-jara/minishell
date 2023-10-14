/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_strarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:01:55 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/14 18:52:00 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// Counts and returns the amount of strings in the NULL-terminated array 'arr'.
static size_t	get_arr2_size(char **arr)
{
	size_t	size;

	size = 0;
	while (*arr)
		size++;
	return (size);
}

// Returns a copy of the NULL-terminated array of strings 'arr' with the string
// 'str' added at the end of it. The original array 'arr' is freed.
char	**add_strarr2(char *str, char **arr)
{
	char	**new_arr;
	size_t	orig_arr_size;
	int		i;

	orig_arr_size = get_arr2_size(arr);
	new_arr = (char **) malloc(sizeof(char *) * (orig_arr_size + 2));
	i = -1;
	while (i++ < orig_arr_size)
	{
		new_arr[i] = ft_strdup(arr[i]);
		if (new_arr[i] == NULL)
			exit (1);
	}
	new_arr[i] = ft_strdup(str);
	if (new_arr[i] == NULL)
		exit (1);
	new_arr[i + 1] = NULL;
	free_strarr2(arr);
	return (new_arr);
}

// Sets the value of the 'i'th string in the 'arr' NULL-terminated
// array to the string 'str'.
// Pre: 'i' must be smaller than the 'arr' size.
char	**set_strarr2(char *str, char **arr, int i)
{
	free(arr[i]);
	arr[i] = ft_strdup(str);
	if (arr[i] == NULL)
		exit (1);
}
