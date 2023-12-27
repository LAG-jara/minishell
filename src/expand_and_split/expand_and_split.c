/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:34:54 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/21 20:47:00 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_and_split_private.h"
#include "token.h"
#include "xtoken.h"

// Expands the variables of the command 'cmd' (as a list of tokens) and splits
// words if needed. Finally, performs quote removal and returns the result.
static t_list	*expand_and_split_cmd(t_list *cmd, int exit_status, char **env)
{
	t_list	*new_cmd;
	t_list	*xtoks;

	xtoks = expand(cmd, exit_status, env);
	lst_clear(&cmd, tok_del);
	split_words(&xtoks);
	remove_quotes(xtoks);
	new_cmd = normalize(xtoks);
	xtoklst_clear(&xtoks);
	return (new_cmd);
}

// Expands the env variables and $? of the 'commands' and split words if needed.
// Finally, performs quote removal and returns the result.
t_list	**expand_and_split(t_list **commands, int exit_status, char **env)
{
	int		i;
	t_token	tok;

	i = -1;
	while (commands[++i])
	{
		commands[i] = expand_and_split_cmd(commands[i], exit_status, env);
		if (commands[i] == NULL)
		{
			tok = tok_create_null();
			commands[i] = lst_new(&tok, sizeof(t_token));
		}
	}
	return (commands);
}
