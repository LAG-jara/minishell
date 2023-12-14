/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:03:26 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:53:07 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

// Sets the value of the 'i'th string in the NULL-terminated array of strings
// 'arr' to the string 'str'. Returns 'arr'.
// Pre: 'i' must be smaller than the 'arr' size.
char	**arrstr_set(char **arr, const char *str, int i)
{
	free(arr[i]);
	arr[i] = ft_strdup(str);
	return (arr);
}
