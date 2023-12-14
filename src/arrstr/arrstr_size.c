/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:32:53 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 12:09:14 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

// Counts and returns the amount of elements in the NULL-terminated array 'arr'.
size_t	arrstr_size(char **arr)
{
	return (arr_size((void *)arr));
}
