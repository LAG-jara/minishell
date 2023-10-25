/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:03:23 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/25 14:33:10 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.assert.h>
#include "basic_utils.h"
/*
pwd
	Print the absolute pathname of the current working directory.
	The return status is 0 unless an error occurs while reading the name of the
	current directory or an invalid option is supplied.
*/

void	pwd_builtin(char **env)
{
	char *buffer;

	buffer = NULL;
	getcwd(buffer, 42);
	write(stdout, &buffer, ft_strlen(buffer));
	free(buffer);
}