/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:03:26 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/15 17:42:52 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrstr.h"

// Sets the value of the 'i'th string in the NULL-terminated array of strings
// 'arr' to the string 'str'. Returns 'arr'.
// Pre: 'i' must be smaller than the 'arr' size.
char	**arrstr_set(const char **arr, char *str, int i)
{
	free(arr[i]);
	arr[i] = ft_strdup(str);
	return (arr);
}
