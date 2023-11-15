/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:58:28 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/14 12:05:39 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Returns the size of the given NULL-terminated array 'arr'.
size_t	arr_size(const void **arr)
{
	size_t	size;

	size = 0;
	while (arr && arr[size])
		++size;
	return (size);
}
