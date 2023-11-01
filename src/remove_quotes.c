/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:25:02 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/01 12:16:19 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "remove_quotes.h"

static void	remove_quotes_xtok(t_xtoken *xtok)
{
	t_xchar	quote;
	t_xchar	dquote;

	if(xtok->type != WORD)
		return ;
	quote = xc_new('\'', UNEXPANDED, UNQUOTED);
	dquote = xc_new('"', UNEXPANDED, UNQUOTED);
	xtok_rm_xcs(xtok, &quote);
	xtok_rm_xcs(xtok, &dquote);
}

// Removes all unquoted ocurrences of ' and " that didn't result form expansion.
// The 'tokens' are expanded and word-splitted.
void	remove_quotes(t_list **xtoks)
{
	while (*xtoks)
	{
		if((*xtoks)->val)
			remove_quotes_xtok((*xtoks)->val);
		*xtoks = (*xtoks)->nxt;
	}
}

/*
#include "debug.h"
//#include ""
 int main()
 {


	t_token	tok = token_create("ho\"'\"'\"a'q\"ue'tal\"?");
	// print_token(tok);
	
	// printf("\n-------------------------\n\n");

	t_xtoken xtok = tok_to_xtok(&tok);
	t_list *list = lst_new(&xtok, sizeof(xtok));
	// t_list *lst = xtoks.val;
	// t_xchar *xc = (t_xchar *)lst->val;
	// xc->x = EXPANDED;
	print_xtoken(*(t_xtoken *)list->val);
	remove_quotes(list);
	print_xtoken(*(t_xtoken *)list->val);
	// printf("\n-------------------------\n\n");
	
	// tok = xtoks_to_tok(&xtoks);
	// print_token(tok);

	// t_xchar	xc = xc_new('l', UNEXPANDED, UNQUOTED);
	// xtoks_rm_xcs(&xtoks, &xc);
	// print_xtoksen(xtoks);
 }
*/