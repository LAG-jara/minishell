/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarr_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:50:58 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/18 13:48:42 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// Frees the NULL-terminated array of strings 'arr'.
void	strarr2_free(char **arr)
{
	int	i;

	i = -1;
	while (arr[i++])
		free(arr[i]);
	free(arr);
}

// Frees the NULL-terminated array of NULL-terminated arrays of strings 'arr'.
void	strarr3_free(char ***arr)
{
	int	i;
	int	j;

	i = -1;
	while (arr[i++])
	{
		j = -1;
		while (arr[j++])
			free(arr[i][j]);
		free(arr[i]);
	}
	free(arr);
}
