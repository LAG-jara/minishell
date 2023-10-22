/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:03:23 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/22 13:03:25 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.c"
/*
pwd
	Print the absolute pathname of the current working directory.
	The return status is 0 unless an error occurs while reading the name of the
	current directory or an invalid option is supplied.
*/

void	pwd_builtin(char **env);
