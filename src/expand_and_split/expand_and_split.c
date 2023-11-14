/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:34:54 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/14 18:06:37 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_and_split.h"

# include "debug.h"
# include "parse_tokens.h"

// Expands the variables of the command 'cmd' (as a list of tokens) and splits
// words if needed. Finally, performs quote removal and returns the result.
static t_list *expand_and_split_cmd(t_list *cmd, int exit_status, char **env)
{
	t_list	*new_cmd;
	t_list	*xtoks;

	xtoks = expand(cmd, exit_status, env);
	lst_clear(&cmd, tok_del);
	split_words(&xtoks);
	remove_quotes(&xtoks);
	new_cmd = normalize(&xtoks);
	xtoklst_clear(&xtoks);
	return (new_cmd);
}

// Expands the env variables and $? of the 'commands' and split words if needed.
// Finally, performs quote removal and returns the result.
t_list	**expand_and_split(t_list **commands, int exit_status, char **env)
{
	int		i;

	i = -1;
	while (commands[++i])
		commands[i] = expand_and_split_cmd(commands[i], exit_status, env);
	return (commands);
}

// TODO free de expansiones "$nada".
int	main(int ac, char **av, char **e)
{
	char **env = arrstr_dup(e);
	ac += 0;
	av += 0;
	int exit_status = 0;
	
	printf("\n");

	char *pre_toks[] = \
	{ "hola$a", "'hola$a'", "\"hola$a\"", NULL};	// TODO: Fix leak with $nada

	t_list	**cmds;
	cmds = parse(pre_toks, &exit_status);
	if (cmds)
		print_cmds(cmds);

	cmds = expand_and_split(cmds, exit_status, env);

	printf("------------------------- 2\n");
	print_cmds(cmds);
	
	env_free(env);
	lst_clear(cmds, tok_del);
	free(cmds);
}
