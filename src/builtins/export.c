/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:03:34 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/22 13:03:37 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.c"
/*
export name=value ...
	The value of the environment variable name is set to value. 
	If the environment variable name doesn’t exist it is created. 
	If no value is given, the value will be set to ””. 
	export returns an exit status of 0 unless one of the names is not a valid 
	shell variable name.

	The text after the ‘=’ undergoes variable expansion and quote removal 
	(but NO word splitting after expansion) before being assigned to the 
	variable.
*/

void	export_builtin(char **comm, char **env);
