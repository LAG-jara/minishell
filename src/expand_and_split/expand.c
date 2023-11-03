/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:49:48 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/03 12:02:57 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_and_split.h"

# include "debug.h"

// Given that the xchar list 'node' points to the '$' character of an 
// environment variable name, expands its value updating the list 'lst'.
// Finally, 'node' points to the xchar right after the expanded variable value.
static void	expand_var(t_list **lst, t_list **node, char **env)
{
	char	*name;
	char	*value;
	int		len;
	t_list	*expanded_lst;

	// printf("original lst:\t");
	// print_lst(*lst, pr_xchar);
	// printf("\n");
	// printf("original node:\t");
	// print_lst(*node, pr_xchar);
	// printf("\n");

	name = xclst_to_str(*node);
	value = get_var(name, env);
	expanded_lst = str_to_xclst(value, EXPANDED, xc_get(*node).q);
	lst_add_many(lst, *node, expanded_lst);
	len = get_name_len(name);
	*node = lst_move(*node, len);
	if (!*node)
		lst_rm_many(lst, lst_move(lst_last(*lst), -(len - 1)), len, free);
	else
		lst_rm_many(lst, lst_move(*node, -len), len, free);

	// printf("final lst:\t");
	// print_lst(*lst, pr_xchar);
	// printf("\n");
	// printf("final node:\t");
	// print_lst(*node, pr_xchar);
	// printf("\n");
	// printf("\n");
}

// Given that 'node' points to the $ character of "$?", expands the value 
// of errno updating the list 'lst'.
// Finally, 'node' points to the xchar right after the expanded errno value.
static void	expand_errno(t_list **lst, t_list **node)
{
	char	*value;
	t_list	*expanded_lst;

	value = ft_itoa(errno);
	expanded_lst = str_to_xclst(value, EXPANDED, xc_get(*node).q);
	free(value);
	lst_add_many(lst, *node, expanded_lst);
	*node = lst_move(*node, 2);
	lst_rm_many(lst, lst_move(*node, -2), 2, free);
}

// Returns TRUE if the list of xchars pointed by 'node' represents a string that
// should trigger an expansion.
// That is, a '$' followed by a '?' or an enviroment variable name.
static int	try_to_expand(t_list *node)
{
	t_xchar	xc;
	t_xchar	xc_next;

	if (!node->nxt)
		return (FALSE);
	xc = xc_get(node);
	xc_next = xc_get(node->nxt);
	if (xc.q != QUOTED && xc.c == '$'
		&& (ft_isalpha(xc_next.c) || xc_next.c == '?'))
		return (TRUE);
	return (FALSE);
}

// Expands the env variables of the given xtoken (if is word), updating the
// expanded xchar flags if needed.
static void	expand_xtok(t_xtoken *xtok, char **env)
{
	t_list	*node;

	if (xtok->type != WORD)
		return ;
	node = xtok->val;
	while (node && node->val)
	{
		if (try_to_expand(node))
		{
			if (((t_xchar *)((node->nxt)->val))->c == '?')
				expand_errno(&(xtok->val), &node);
			else
				expand_var(&(xtok->val), &node, env);
		}
		else
			node = node->nxt;
	}
}

// Given a list of tokens, allocates and returns a list of xtokens with its
// $VARIABLES expanded, preserving the original token type and setting each
// character's flags for expanded and quoted status.
t_list	*expand(t_list *toks, char **env)
{
	t_list		*xtoks;
	t_xtoken	xtok;
	t_list		*node;
	int			skip_next;

	skip_next = FALSE;
	xtoks = NULL;
	node = toks;
	while (node)
	{
		xtok = tok_to_xtok((t_token *)node->val);
		if (xtok.type == WORD)
		{
			if (skip_next)
				skip_next = FALSE;
			else
				expand_xtok(&xtok, env);
		}
		else if (!ft_strncmp(node->val, "<<", 3))
			skip_next = TRUE;
		lst_add(&xtoks, lst_new(&xtok, sizeof(xtok)));
		node = node->nxt;
	}
	return (xtoks);
}


# include "debug.h"
# include "parse_tokens.h"

// int	main(int ac, char **av, char **e)
// {
// 	char	**env = arrstr_dup(e);
// 	// e += 0;
// 	ac += 0;
// 	av += 0;

// 	char *pre_toks[] = \
// 	{ "a$?Im_da_BOSS", "'Holis  mundo'", "\"hola||\"$USER", ">", "outfile", NULL};

// 	t_list	**cmds;
// 	cmds = parse(pre_toks);
// 	if (cmds)
// 		print_cmds(cmds);

// 	printf("-------------------------\n");

// 	t_list	*cmd = expand(cmds[0], env);

// 	print_lst(cmd, pr_xtoken);
// 	// t_list	*cmd = cmds[0];
// 	// t_token	tok = *(t_token *)cmd->val;
// 	// t_xtoken xtok = tok_to_xtok(&tok);
	
// 	// print_xtoken(xtok);

// 	// printf("-------------------------\n");
	
// 	// expand_xtok(&xtok, env);
// 	// print_xtoken(xtok);

// 	printf("\n");
// }
