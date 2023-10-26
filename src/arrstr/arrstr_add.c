/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:42:30 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 12:26:13 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrstr_utils.h"

// Allocates and returns a copy of the NULL-terminated array of strings 'arr'
// with the string 'str' added at the end of it.
// The original array 'arr' is freed. Exits properly if memory allocation fails.
char	**arrstr_add(char **arr, char *str)
{
	char	**new_arr;
	int		orig_arr_size;
	int		i;

	orig_arr_size = arrstr_size(arr);
	new_arr = (char **) p_malloc(sizeof(char *) * (orig_arr_size + 2));
	i = -1;
	while (++i < orig_arr_size)
		new_arr[i] = ft_strdup2(arr[i]);
	new_arr[i] = ft_strdup2(str);
	new_arr[i + 1] = NULL;
	arrstr_free(arr);
	return (new_arr);
}

// Allocates and returns a copy of the array of arrays of strings 'arr'
// with the "sub-array" 'subarr' added at the end of it.
// The original array 'arr' is freed.
// Exits properly if memory allocation fails.
char	***aarrstr_add(char ***arr, char **subarr)
{
	char	***new_arr;
	int		orig_arr_size;
	int		i;

	orig_arr_size = aarrstr_size(arr);
	new_arr = (char ***) p_malloc(sizeof(char *) * (orig_arr_size + 2));
	i = -1;
	while (++i < orig_arr_size)
		new_arr[i] = arrstr_dup(arr[i]);
	new_arr[i] = arrstr_dup(subarr);
	new_arr[i + 1] = NULL;
	aarrstr_free(arr);
	return (new_arr);
}
