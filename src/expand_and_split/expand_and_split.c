/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:34:54 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/22 12:56:23 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_and_split.h"

// Expands the variables of the command 'cmd' (as a list of tokens) and splits
// words if needed. Finally, performs quote removal and returns the result.
static t_list	*expand_and_split_cmd(t_list *cmd, int exit_status, char **env)
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

// # include "debug.h"
// # include "parse_tokens.h"
// # include "tokenize.h"

// int	main(int ac, char **av, char **e)
// {
// 	av++;
// 	ac--;
// 	char **env = arrstr_dup(e);
// 	int exit_status;
// 	char *input = "cd directorio \"$USER\" caca > uno '$USER' > caca | echo $USER | rm -fr *";

// 	t_list	*tokens = tokenize(input);
// 	// printf("\n___________________TOKENIZE\n");
// 	// print_lst(tokens, pr_token);

// 	t_list	**cmds;
// 	cmds = parse(tokens, &exit_status);
// 	printf("\n______________________PARSE\n");
// 	if (cmds)
// 		print_cmds(cmds);
// 	printf("Exit status: %d\n", exit_status);

// 	cmds = expand_and_split(cmds, exit_status, env);
// 	printf("\n___________EXPAND AND SPLIT\n");
// 	print_cmds(cmds);

// 	env_free(env);
// 	lst_clear(cmds, tok_del);
// 	free(cmds);
// }
