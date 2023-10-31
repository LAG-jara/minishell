/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:49:48 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/31 19:00:59 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
# include "xtoken.h"

// Given that the xchar list 'node' points to the '$' character of an 
// environment variable name, expands its value updating the list 'lst'.
void	expand_var(t_list **lst, t_list *node, char **env)
{
	char	*name;
	char	*val;
	int		namelen;
	t_list	*expanded_lst;

	name = xclst_to_str(node);
	val = get_var(name, env);
	expanded_lst = str_to_xclst(val, EXPANDED, (*(t_xchar *)node->val).q);
	namelen = get_name_len(name);
	expanded_lst = NULL;

}

// Given that 'node' points to the $ character of "$?", expands the value 
// of errno updating the list 'lst'.
static char	*expand_errno(t_list **lst, t_list *node)
{
	char	*val;

	val = ft_itoa(errno);
	
}

// Returns TRUE if the list of xchars pointed by 'node' represents a string that
// should trigger an expansion.
// That is, a '$' followed by a '?' or an enviroment variable name.
static int	try_to_expand(t_list *node)
{
	int		ret;
	t_xchar	*xc;
	t_xchar	*xc_next;

	if (!node->nxt)
		return (FALSE);
	xc = (t_xchar *)node;
	xc_next = (t_xchar *)node->nxt;
	if (xc->q != QUOTED && xc->c == '$'
		&& (ft_isalpha(xc_next->c) || xc_next == '?'))
		return (TRUE);
	return (FALSE);
}

// Expands the env variables of the given xtoken (if is word), updating the
// expanded xchar flags if needed.
static void	expand_xtok(t_token	*xtok, char **env)
{
	t_list	*curr_node;
	t_list	*expanded_val;

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
				expand_var(&(xtok->val), curr_node, env);
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

int	main(void)
{
	char *pre_toks[] = \
	{ "ls", "arg1", "arg2", "|", "echo", "Holis", ":)", ">", "outfile", NULL};

	
}
