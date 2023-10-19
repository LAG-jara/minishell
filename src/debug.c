/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:14:27 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/19 10:39:22 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

// DEBUG ONLY!
void	print_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		printf("[%d] : %s\n", i, arr[i]);
}

// DEBUG ONLY!
void	print_cmds(char ***cmds)
{
	int	i;

	i = 0;
	while (cmds && cmds[i])
	{
		printf("CMD %d:\n", i);
		print_arr(cmds[i]);
		printf("\n");
		++i;
	}
}
