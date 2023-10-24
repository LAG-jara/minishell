/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:03:52 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/22 13:03:54 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
/*
unset [name ...]
	For each name, remove the corresponding variable. 
	Each name refers to a shell variable. Read-only variables may not be unset.
	Each unset variable is removed from the environment passed to subsequent 
	commands. 
	The exit status is true unless a name is readonly.
*/

void	unset_builtin(char **word, char ***env)
{
	char	*value;
	char	*varname;
	int		i;

	n_word = strarr2_get_size(word);
	while (*word)
	{
		i = -1;
		while(*word[++i])
			rm_env_var(varname, *(word + i), env);
		++word;
	}
}
