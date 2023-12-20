/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:03:23 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:04:59 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include "print_error.h"
#include <unistd.h>

// Prints the actual path. Returns 0.
int	pwd_builtin(void)
{
	char	*buffer;

	buffer = NULL;
	buffer = getcwd(buffer, 42);
	if (!buffer)
	{
		print_err_builtin("pwd", NULL);
		return (2);
	}
	write(1, buffer, ft_strlen(buffer));
	write(1, "\n", 1);
	free(buffer);
	return (0);
}
