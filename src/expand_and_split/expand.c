/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:49:48 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/03 19:23:00 by glajara-         ###   ########.fr       */
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

	name = xclst_to_str(*node);
	value = get_var(name, env);
	expanded_lst = str_to_xclst(value, EXPANDED, xc_get(*node).q);
	lst_add_many(lst, *node, expanded_lst);
	len = get_name_len(name);
	free(name);
	*node = lst_move(*node, len);
	if (!*node)
		lst_rm_many(lst, lst_move(lst_last(*lst), -(len - 1)), len, free);
	else
		lst_rm_many(lst, lst_move(*node, -len), len, free);
}

// Given that 'node' points to the $ character of "$?", expands the value 
// of errno updating the list 'lst'.
// Finally, 'node' points to the xchar right after the expanded errno value.
static void	expand_errno(t_list **lst, t_list **node)
{
	char	*value;
	t_list	*expanded_lst;

	// printf("original lst:\t");
	// print_lst(*lst, pr_xchar);
	// printf("\noriginal node:\t");
	// print_lst(*node, pr_xchar);
	// printf("\n");

	value = ft_itoa(errno);
	expanded_lst = str_to_xclst(value, EXPANDED, xc_get(*node).q);
	free(value);

	// printf("expanded:\t");
	// print_lst(expanded_lst, pr_xchar);
	// printf("\n");

	lst_add_many(lst, *node, expanded_lst);

	// printf("added list:\t");
	// print_lst(*lst, pr_xchar);
	// printf("\n");

	*node = lst_move(*node, 2);

	// printf("moved node:\t");
	// print_lst(*node, pr_xchar);
	// printf("\n");

	if (!*node)
		lst_rm_many(lst, lst_move(lst_last(*lst), - 1), 2, free);
	else
		lst_rm_many(lst, lst_move(*node, -2), 2, free);

	// printf("final lst:\t");
	// print_lst(*lst, pr_xchar);
	// printf("\n");
	// printf("final node:\t");
	// print_lst(*node, pr_xchar);
	// printf("\n");
	// printf("\n");
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
