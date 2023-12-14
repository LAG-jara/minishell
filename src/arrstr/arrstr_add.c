/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:42:30 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:51:48 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrstr.h"
#include "basic_utils.h"

// Allocates and returns a copy of the NULL-terminated array of strings 'arr'
// with the string 'str' added at the end of it.
// The original array 'arr' is freed. Exits properly if memory allocation fails.
char	**arrstr_add(char **arr, const char *str)
{
	char	**new_arr;
	int		orig_arr_size;
	int		i;

	orig_arr_size = arrstr_size(arr);
	new_arr = (char **)p_malloc(sizeof(char *) * (orig_arr_size + 2));
	i = -1;
	while (++i < orig_arr_size)
		new_arr[i] = ft_strdup(arr[i]);
	new_arr[i] = ft_strdup(str);
	new_arr[i + 1] = NULL;
	arrstr_free(arr);
	return (new_arr);
}
