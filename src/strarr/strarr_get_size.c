/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarr_get_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:32:53 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/18 12:47:55 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Counts and returns the amount of elements in the NULL-terminated array 'arr'.
size_t	strarr2_get_size(char **arr)
{
	size_t	size;

	size = 0;
	while (arr[size])
		++size;
	return (size);
}

// Counts and returns the amount of elements in the NULL-terminated array 'arr'.
size_t	strarr3_get_size(char ***arr)
{
	size_t	size;

	size = 0;
	while (arr[size])
		++size;
	return (size);
}
