/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:11:43 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/30 13:05:38 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Recives the expanded, splited, quote-removed tokens and converts them into a
// t_token array.
t_list	*normalize(t_list **xtokens)
{
	t_list	*cmd;
	t_list	*xtoks;
	t_token tok;
	t_list	*new_tok;

	cmd = NULL;
	new_tok = NULL;
	xtoks = *xtokens;
	while (xtoks)
	{
		tok = xtok_to_tok((t_xtoken *)xtoks);
		new_tok = lst_new(&tok, sizeof(t_token));
		lst_add(&cmd, new_tok);
		xtoks = xtoks->nxt;
	}
	//while(*tokens)
	//	lst_rm_one(tokens, *tokens, xtok_rm_one())
	return (cmd);
}
