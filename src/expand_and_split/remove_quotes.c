/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:25:02 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 18:59:09 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"
#include "quote_utils.h"
#include "boolean.h"

// Removes all unquoted ocurrences of ' and " that didn't result form expansion.
static void	remove_quotes_xtok(t_xtoken *xtok)
{
	t_xchar	quote;
	t_xchar	dquote;

	if (xtok->type != WORD)
		return ;
	quote = xc_new('\'', UNEXPANDED, UNQUOTED);
	dquote = xc_new('"', UNEXPANDED, UNQUOTED);
	xtok_rm_xcs(xtok, &quote);
	xtok_rm_xcs(xtok, &dquote);
}

// For each word on the 'xtokens' list, removes all unquoted ocurrences of 
// ' and " that didn't result form expansion (excluding those after << redirs).
void	remove_quotes(t_list *xtokens)
{
	t_xtoken	*xtok;
	t_list		*node;
	int			skip_next;

	skip_next = FALSE;
	node = xtokens;
	while (node)
	{
		xtok = xtok_get(node);
		if (xtok->type == WORD)
		{
			if (skip_next)
				skip_next = FALSE;
			else
				remove_quotes_xtok(xtok);
		}
		else if (!xtok_strncmp(xtok, "<<", 3))
			skip_next = TRUE;
		node = node->nxt;
	}
}
