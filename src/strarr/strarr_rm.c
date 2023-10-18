/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarr_rm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:07:22 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/18 12:47:54 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strarr_utils.h"

// Allocates and returns a copy of the NULL-terminated array of strings 'arr'
// with the 'i'th string removed from it.
// The original array 'arr' is freed.
char	**strarr2_rm(char **arr, int i)
{
	char	**old_arr;
	char	**new_arr;
	size_t	orig_arr_size;
	int		j;

	old_arr = arr;
	orig_arr_size = strarr2_get_size(old_arr);
	new_arr = (char **) p_malloc(sizeof(char *) * orig_arr_size);
	j = -1;
	while (old_arr[++j])
	{
		if (j == i)
			++old_arr;
		new_arr[j] = ft_strdup2(old_arr[j]);
	}
	new_arr[j] = NULL;
	strarr2_free(arr);
	return (new_arr);
}
