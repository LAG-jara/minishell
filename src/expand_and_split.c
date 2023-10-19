/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:34:54 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/19 12:00:49 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_and_split.h"
#include "expand_vars.h"
#include "split_words.h"
#include "remove_quotes.h"

// Expands the variables of the token and splits words if needed.
// Finally, performs quote removal and returns the result.
static char	**expand_and_split_token(char *token, char **env)
{
	int		*expanded;
	char	**split_tok;

	token = expand_vars(token, &expanded, env);
	// split_tok = split_words(token, expanded);
	// split_tok = remove_quotes(split_tok, expanded);
	return (split_tok);
}

// Expands the variables of the command and splits words if needed.
// Finally, performs quote removal and returns the result.
static char	**expand_and_split_cmd(char **cmd, char **env)
{
	char	**split_tok;
	int		i;

	i = -1;
	while (cmd[++i])
	{
		split_tok = expand_and_split_token(cmd[i], env);
		cmd = strarr2_add_subarr_at(cmd, split_tok, i);
	}
	return (cmd);
}

// Expands the variables of the 'commands' and split words if needed.
// Finally, performs quote removal and returns the result.
char	***expand_and_split(char ***commands, char **env)
{
	char	**cmd;
	int		i;

	i = -1;
	while (commands[++i])
		commands[i] = expand_and_split_cmd(commands[i], env);
	return (commands);
}
