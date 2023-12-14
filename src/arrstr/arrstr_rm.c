/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_rm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:07:22 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:52:34 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrstr.h"
#include "basic_utils.h"

// Allocates and returns a copy of the NULL-terminated array of strings 'arr'
// with the 'i'th string removed from it. The original array 'arr' is freed.
// Exits properly if memory allocation fails.
char	**arrstr_rm(char **arr, int i)
{
	char	**orig_arr;
	char	**new_arr;
	int		orig_arr_size;
	int		j;

	orig_arr = arr;
	orig_arr_size = arrstr_size(orig_arr);
	new_arr = (char **)p_malloc(sizeof(char *) * orig_arr_size);
	j = -1;
	while (++j < i)
		new_arr[j] = ft_strdup(orig_arr[j]);
	while (orig_arr[j + 1])
	{
		new_arr[j] = ft_strdup(orig_arr[j + 1]);
		++j;
	}
	new_arr[j] = NULL;
	arrstr_free(arr);
	return (new_arr);
}
