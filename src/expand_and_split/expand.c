/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:49:48 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/20 12:55:42 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"
#include "env.h"
#include "quote_utils.h"
#include <stdlib.h>				// free
#include "basic_utils.h"		// ft_itoa

// Given that the xchar list 'node' points to the '$' character of an 
// environment variable name, expands its value updating the list 'lst'.
// Finally, 'node' points to the xchar right after the expanded variable value.
static void	expand_var(t_list **lst, t_list **node, char **env)
{
	char	*name;
	char	*value;
	int		len;
	t_list	*expanded_lst;

	*node = (*node)->nxt;
	name = xclst_to_str(*node);
	value = env_get_var(name, env);
	expanded_lst = str_to_xclst(value, EXPANDED, xc_get(*node).q);
	lst_add_many(lst, (*node)->pre, expanded_lst);
	len = env_name_len(name);
	free(name);
	*node = lst_move(*node, len);
	if (!*node)
		lst_rm_many(lst, lst_move(lst_last(*lst), -(len)), len + 1, free);
	else
		lst_rm_many(lst, lst_move(*node, -(len + 1)), len + 1, free);
}

// Given that 'node' points to the $ character of "$?", expands the value 
// of 'exit_status' updating the list 'lst'.
// Finally, 'node' points to the xchar right after the expanded value.
static void	expand_exit_stat(t_list **lst, t_list **node, int exit_status)
{
	char	*value;
	t_list	*expanded_lst;

	value = ft_itoa(exit_status);
	expanded_lst = str_to_xclst(value, EXPANDED, xc_get(*node).q);
	free(value);
	lst_add_many(lst, *node, expanded_lst);
	*node = lst_move(*node, 2);
	if (!*node)
		lst_rm_many(lst, lst_move(lst_last(*lst), -1), 2, free);
	else
		lst_rm_many(lst, lst_move(*node, -2), 2, free);
}

// Returns TRUE if the list of xchars pointed by 'node' represents a string that
// should trigger an expansion.
// That is, a '$' followed by a '?' or a valid environment variable name.
static int	try_to_expand(t_list *node)
{
	t_xchar	xc;
	t_xchar	xc_next;

	if (!node->nxt)
		return (FALSE);
	xc = xc_get(node);
	xc_next = xc_get(node->nxt);
	if (xc.q != QUOTED && xc.c == '$'
		&& (ft_isalpha(xc_next.c) || xc_next.c == '?' || xc_next.c == '_'))
		return (TRUE);
	return (FALSE);
}

// Expands the env variables (or exit status) of the given xtoken (if is word),
// updating the expanded xchar flags if needed.
static void	expand_xtok(t_xtoken *xtok, int exit_status, char **env)
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
				expand_exit_stat(&(xtok->val), &node, exit_status);
			else
				expand_var(&(xtok->val), &node, env);
		}
		else
			node = node->nxt;
	}
}

// Given a list of tokens, allocates and returns a list of xtokens with its
// environment variables (or exit status) expanded, preserving the original
// token type and setting each character's flags for expanded and quoted status.
t_list	*expand(t_list *toks, int exit_status, char **env)
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
				expand_xtok(&xtok, exit_status, env);
		}
		else if (!xtok_strncmp(&xtok, "<<", 3))
			skip_next = TRUE;
		lst_add(&xtoks, lst_new(&xtok, sizeof(xtok)));
		node = node->nxt;
	}
	return (xtoks);
}
