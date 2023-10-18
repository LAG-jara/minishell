/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarr_add_subarr_at.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:09:24 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/18 12:48:00 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strarr_utils.h"

// Allocates and returns a copy of the NULL-terminated array of strings 'arr'
// with the 'i'th element replaced by the "sub-array" of strings 'subarr'.
// Both the original array 'arr' and the added 'subarr' are freed.
char	**strarr2_add_subarr_at(char **arr, char **subarr, int i)
{
	char	**new_arr;
	size_t	new_arr_size;
	int		j;
	int		k;

	new_arr_size = get_strarr2_size(arr) + get_strarr2_size(subarr);
	new_arr = (char **) p_malloc(sizeof(char *) * (new_arr_size + 1));
	j = -1;
	while (arr[++j] && j != i)
		new_arr[j] = ft_strdup2(arr[j]);
	k = j;
	while (*subarr)
		new_arr[++j] = ft_strdup2(*subarr++);
	while (arr[++k])
		new_arr[++j] = ft_strdup2(arr[k]);
	new_arr[j + 1] = NULL;
	free_strarr2(arr);
	free_strarr2(subarr);
	return (new_arr);
}
