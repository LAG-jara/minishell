/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_fill_idx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:09:24 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 14:08:21 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrstr_utils.h"

// Allocates and returns a copy of the NULL-terminated array of strings 'arr'
// with the 'i'th element replaced by the "sub-array" of strings 'subarr'.
// Both the original array 'arr' and the added 'subarr' are freed.
// Exits properly if memory allocation fails.
char	**arrstr_fill_idx(char **arr, char **subarr, int i)
{
	char	**new_arr;
	size_t	new_arr_size;
	int		j;
	int		k;

	new_arr_size = arrstr_size(arr) + arrstr_size(subarr) - 1;
	new_arr = (char **) p_malloc(sizeof(char *) * (new_arr_size + 1));
	j = -1;
	while (arr[++j] && j != i)
		new_arr[j] = ft_strdup(arr[j]);
	k = j;
	while (*subarr)
		new_arr[j++] = ft_strdup(*subarr++);
	while (arr[++k])
		new_arr[j++] = ft_strdup(arr[k]);
	new_arr[j] = NULL;
	// arrstr_free(arr);
	// arrstr_free(subarr);		// TODO: Check that line 👀
	return (new_arr);
}

// #include "debug.h"
// int	main(int ac, char **av, char **environ)
// {
// 	char **env = arrstr_dup(environ);

// 	print_arrstr(env);

// 	char *tmp[] = { "esto es un array", "ESTO ES OTRO ARRAY", "AQUI HAY OTRO", NULL };
// 	char **subarr = arrstr_dup(tmp);
// 	env = arrstr_fill_idx(env, subarr, 5);
// 	printf("\n\n");

// 	print_arrstr(env);
// }