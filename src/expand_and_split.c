/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:34:54 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/27 13:39:32 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_and_split.h"
# include "debug.h"

// Expands the variables of the command and splits words if needed.
// Finally, performs quote removal and returns the result.
static char	**expand_and_split_cmd(char **cmd, char **env)
{
	t_lst	toks;

	toks = expand(cmd, env);
	toks = split_words(toks);
	toks = remove_quotes(toks);
	cmd = normalize(toks);
	return (cmd);
}

// Expands the variables of the 'commands' and split words if needed.
// Finally, performs quote removal and returns the result.
char	***expand_and_split(char ***commands, char **env)
{
	int		i;

	i = -1;
	while (commands[++i])
		commands[i] = expand_and_split_cmd(commands[i], env);
	return (commands);
}
