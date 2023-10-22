/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:03:02 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/22 13:03:05 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.c"
/*
cd [dir]
	Change the current directory to dir. The variable HOME is the default dir. 
	The variable CDPATH defines the search path for the directory 
	containing dir. 
	Alternative directory names in CDPATH are separated by a colon (:). 
	A null directory name in CDPATH is the same as the current directory, 
	i.e., ".".
	If dir begins with a slash (/), then CDPATH is not used. 
	If a non-empty directory name from CDPATH is used and the directory change 
	is successful, the absolute pathname of the new working directory is 
	written directory the standard output.
	The return value is true if the directory was successfully changed;
	false otherwise.
*/

void	cd_builtin(char **comm, char **env);