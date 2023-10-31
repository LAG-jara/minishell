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
t_token	*normalize(t_xtoken *toks)
{
	t_token	*cmd;

	cmd = NULL;
	lst
	while (toks)
	{
		cmd = tok_add(&cmd, xtok_to_tok(toks));
		
		toks = toks->nxt;
	}
}
