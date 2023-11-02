/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:34:54 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/01 12:29:04 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_and_split.h"

# include "debug.h"

// Expands the variables of the command 'cmd' (as a list of tokens) and splits
// words if needed. Finally, performs quote removal and returns the result.
static t_list *expand_and_split_cmd(t_list *cmd, char **env)
{
	t_list	*new_cmd;
	t_list	*xtoks;

	xtoks = expand(cmd, env);
	// split_words(&xtoks);
	remove_quotes(&xtoks);

	print_lst(xtoks, pr_xtoken);
	new_cmd = normalize(&xtoks);
	print_lst(new_cmd, pr_token);
	//return (cmd);
	return (new_cmd);
}

// Expands the variables of the 'commands' and split words if needed.
// Finally, performs quote removal and returns the result.
t_list	**expand_and_split(t_list **commands, char **env)
{
	int		i;

	i = -1;
	while (commands[++i])
		commands[i] = expand_and_split_cmd(commands[i], env);
	return (commands);
}

# include "parse_tokens.h"
int	main(int ac, char **av, char **e)
{
	char **env = arrstr_dup(e);
	ac += 0;
	av += 0;

	char *pre_toks[] = \
	{ "a\"hola\"", "'Holis  mundo'", "\"hola||\"$USER", ">", "outfile", NULL};

	t_list	**cmds;
	cmds = parse(pre_toks);
	if (cmds)
		print_cmds(cmds);

	printf("-------------------------\n");

	cmds[0] = expand_and_split_cmd(cmds[0], env);
	// if (cmds)
	// 	print_cmds(cmds);

}