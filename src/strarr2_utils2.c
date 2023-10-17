/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarr2_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:40:34 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/17 19:04:08 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strarr2.h"
#include "basic_utils.h"

// Allocates and returns a copy of the NULL-terminated array of strings 'arr'
// with the 'i'th element replaced by the "sub-array" of strings 'subarr'.
// Both the original array 'arr' and the added 'subarr' are freed.
char	**add_subarr_at_strarr2(char **arr, char **subarr, int i)
{
	char	**new_arr;
	size_t	orig_arr_size;
	size_t	subarr_size;
	int		j;
	int		k;

	orig_arr_size = get_strarr2_size(arr);
	subarr_size = get_strarr2_size(subarr);
	new_arr = malloc(sizeof(char *) * (orig_arr_size + subarr_size + 1));
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