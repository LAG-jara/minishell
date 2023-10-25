/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarr_rm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:07:22 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/25 16:24:32 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strarr_utils.h"

// Allocates and returns a copy of the NULL-terminated array of strings 'arr'
// with the 'i'th string removed from it. The original array 'arr' is freed.
// Exits properly if memory allocation fails.
char	**strarr2_rm(char **arr, int i)
{
	char	**orig_arr;
	char	**new_arr;
	int		orig_arr_size;
	int		j;

	orig_arr = arr;
	orig_arr_size = strarr2_get_size(orig_arr);
	new_arr = (char **) p_malloc(sizeof(char *) * orig_arr_size);
	j = -1;
	while (++j < orig_arr_size)
	{
		if (j == i)
			++orig_arr;
		new_arr[j] = ft_strdup2(orig_arr[j]);
	}
	new_arr[j] = NULL;
	strarr2_free(arr);
	return (new_arr);
}
