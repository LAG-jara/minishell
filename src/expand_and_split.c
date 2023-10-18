/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:34:54 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/18 17:27:46 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_and_split.h"

static char	*expand_token(char *token)
{
	
}

static char	**split_token(char **cmd)
{

}

char	**expand_and_split_cmd(char **cmd)
{
	char	*token;
	int		i;
	int		has_expanded;

	i = -1;
	while (cmd[++i])
	{
		has_expanded = FALSE;
		cmd[i] = expand_token(cmd[i]);

	}

}

// Expands the variables and split words if needed.
char	***expand_and_split(char ***commands, char **env)
{
	char	**cmd;
	int		i;

	i = -1;
	while (commands[++i])
		commands[i] = expand_and_split_cmd(commands[i]);
	return (commands);
}
