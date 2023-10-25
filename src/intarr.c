/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intarr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:16:39 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/25 16:27:17 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intarr_utils.h"

// Counts and returns the amount of numbers in the array 'arr' (ending with -1).
int	intarr_get_size(int *arr)
{
	int	size;

	size = 0;
	while (arr && arr[size] != -1)
		++size;
	return (size);
}

// Allocates and returns a copy of the array of integers 'arr' (ending with -1).
// Exits properly if memory allocation fails.
int	*intarr_dup(int *arr)
{
	int		*new_arr;
	int		orig_arr_size;
	int		i;

	orig_arr_size = intarr_get_size(arr);
	new_arr = (int *) p_malloc(sizeof(int) * (orig_arr_size + 1));
	i = -1;
	while (++i < orig_arr_size)
		new_arr[i] = arr[i];
	new_arr[i] = -1;
	return (new_arr);
}

// Allocates and returns a copy of the array of integers 'arr' (ending with -1)
// with the integer 'n' added at the end of it.
// The original array 'arr' is freed. Exits properly if memory allocation fails.
int	*intarr_add(int *arr, int n)
{
	int		*new_arr;
	int		orig_arr_size;
	int		i;

	orig_arr_size = intarr_get_size(arr);
	new_arr = (int *) p_malloc(sizeof(int) * (orig_arr_size + 2));
	i = -1;
	while (++i < orig_arr_size)
		new_arr[i] = arr[i];
	new_arr[i] = n;
	new_arr[i + 1] = -1;
	free(arr);
	return (new_arr);
}
