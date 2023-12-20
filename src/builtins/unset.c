/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:03:52 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/20 12:44:48 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "print_error.h"

// Unset every variable in args from env. 
// If no errors are found, returns 0.
// Otherwise returns error with the proper message and exit_status.
int	unset_builtin(char **args, char ***env)
{
	int	i;
	int	ret_status;

	i = -1;
	ret_status = 0;
	while (args[++i])
	{
		if (env_valid_varname(args[i]))
			env_rm_var(args[i], env);
		else
			ret_status = print_err_identifier("unset", args[i]);
	}
	return (ret_status);
}
