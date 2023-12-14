/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:39:09 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:52:13 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrstr.h"
#include "basic_utils.h"

// Allocates and returns a copy of the NULL-terminated array of strings 'arr'.
// Exits properly if memory allocation fails.
char	**arrstr_dup(char **arr)
{
	char	**new_arr;
	int		orig_arr_size;
	int		i;

	orig_arr_size = arrstr_size(arr);
	new_arr = (char **)p_malloc(sizeof(char *) * (orig_arr_size + 1));
	i = -1;
	while (++i < orig_arr_size)
		new_arr[i] = ft_strdup(arr[i]);
	new_arr[i] = NULL;
	return (new_arr);
}
