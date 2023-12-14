/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:11:43 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/14 16:06:13 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "xtoken.h"

// Recives the expanded, splited, quote-removed xtokens and converts them into a
// token list(cmd).
t_list	*normalize(t_list *xtokens)
{
	t_list	*cmd;
	t_list	*xtok;
	t_token	tok;
	t_list	*new_tok;

	cmd = NULL;
	xtok = xtokens;
	while (xtok)
	{
		tok = xtok_to_tok(xtok->val);
		new_tok = lst_new(&tok, sizeof(tok));
		lst_add(&cmd, new_tok);
		xtok = xtok->nxt;
	}
	return (cmd);
}
