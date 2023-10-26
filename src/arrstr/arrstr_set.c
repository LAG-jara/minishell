/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:03:26 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 12:11:23 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrstr_utils.h"

// Sets the value of the 'i'th string in the NULL-terminated array of strings
// 'arr' to the string 'str'. Returns 'arr'.
// Pre: 'i' must be smaller than the 'arr' size.
char	**arrstr_set(char **arr, char *str, int i)
{
	free(arr[i]);
	arr[i] = ft_strdup2(str);
	return (arr);
}

// Sets the value of the 'i'th string in the NULL-terminated array of arrays
// of strings 'arr' to the "sub-array" 'subarr'. Returns 'arr'.
// Pre: 'i' must be smaller than the 'arr' size.
char	***aarrstr_set(char ***arr, char **subarr, int i)
{
	free(arr[i]);
	arr[i] = arrstr_dup(subarr);
	return (arr);
}
