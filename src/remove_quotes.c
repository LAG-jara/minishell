/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:25:02 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/30 11:02:12 by glajara-         ###   ########.fr       */
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
static void	rm_quotes_xtok(t_xtoken *tok)
{
	curr_tok = tok;
	while (curr_tok)
	{
		if(is_quote_to_rm(curr_tok))
			xtok_rm(&tok, &curr_tok);
		curr_tok = curr_tok->nxt;
	}
}

// Removes all unquoted ocurrences of ' and " that didn't result form expansion.
// The 'tokens' are expanded and word-splitted.
t_xtoken	*remove_quotes(t_xtoken *tokens)
{
	t_xtoken	*curr_tok;

	curr_tok = tokens;
	while (curr_tok && curr_tok->type == WORD)
	{
		rm_quotes_xtok(curr_tok->val);
		curr_tok = curr_tok->nxt;
	}
	return (tokens);
}
