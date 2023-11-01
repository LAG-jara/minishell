/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:49:48 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/01 10:55:00 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
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
	// printf("original node:\t");
	// print_lst(*node, pr_xchar);
	name = xclst_to_str(*node);
	value = get_var(name, env);
	expanded_lst = str_to_xclst(value, EXPANDED, xc_get(*node).q);
	lst_add_many(lst, *node, expanded_lst);
	len = get_name_len(name);
	*node = lst_move(*node, len);
	lst_rm_many(lst, lst_move(*node, -len), len, free);
	// printf("final node:\t");
	// print_lst(*node, pr_xchar);
	// printf("final lst:\t");
	// print_lst(*lst, pr_xchar);
}

// Given that 'node' points to the $ character of "$?", expands the value 
// of errno updating the list 'lst'.
// Finally, 'node' points to the xchar right after the expanded errno value.
static void	expand_errno(t_list **lst, t_list *node)
{
	char	*val;

	val = ft_itoa(errno);
	lst_move(*lst, 0);
	lst_move(node, 0);
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
	t_list	*curr_node;

	if (xtok->type != WORD)
		return ;
	curr_node = xtok->val;
	while (curr_node && curr_node->val)
	{
		if (try_to_expand(curr_node))
		{
			if (((t_xchar *)((curr_node->nxt)->val))->c == '?')
				expand_errno(&(xtok->val), curr_node);
			else
				expand_var(&(xtok->val), &curr_node, env);
		}
		// MAS
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
		lst_add(&xtoks, lst_new(&xtok, sizeof(t_xtoken)));
		node = node->nxt;
	}
	return (xtoks);
}


# include "debug.h"
# include "parse_tokens.h"

int	main(int ac, char **av, char **e)
{
	char	**env = arrstr_dup(e);
	ac += 0;
	av += 0;

	char *pre_toks[] = \
	{ "$$USER.BOSS", "Holis", ":)", ">", "outfile", NULL};

	t_list	**cmds;
	cmds = parse(pre_toks);
	if (cmds)
		print_cmds(cmds);

	t_list	*cmd = cmds[0];
	t_token	tok = *(t_token *)cmd->val;
	t_xtoken xtok = tok_to_xtok(&tok);
	
	print_xtoken(xtok);

	printf("-------------------------\n");
	
	if (xtok.type != WORD)
		exit(1);
	t_list	*lst = xtok.val;
	t_list	*node = lst->nxt;
	expand_var(&lst, &node, env);
	
	print_xtoken(xtok);
	printf("\n");
}
