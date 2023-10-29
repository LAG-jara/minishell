/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:25:02 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 18:14:57 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "remove_quotes.h"
//# include "debug.h"

// Returns TRUE if 'c' is an unquoted quote that didn't result from expansion.
static int	is_quote_to_rm(t_xchar *xc)
{
	if (xc->q == UNQUOTED && xc->x == UNEXPANDED
		&& (xc->c == '\'' || xc->c == '"'))
		return (TRUE);
	return (FALSE);
}

// Removes all unquoted ocurrences of ' and " that didn't result form expansion,
// taking (and updating) the given 'q_stat' and 'i' into account.
static void	rm_quotes_tok(t_lst *tok)
{

	while (tok)
	{
		if(is_quote_to_rm(tok))
			doblst_del_node(tok);
		tok = tok->nxt;
	}
}

// Removes all unquoted ocurrences of ' and " that didn't result form expansion.
// The 'tokens' are expanded and word-splitted.
t_lst	*remove_quotes(t_lst *tokens)
{
	t_lst	*curr_tok;

	curr_tok = tokens;
	while (curr_tok)
	{
		rm_quotes_tok(curr_tok->val);
		curr_tok = curr_tok->nxt;
	}
	return (tokens);
}
