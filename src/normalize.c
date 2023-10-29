/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:11:43 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/29 13:11:44 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Recives the expanded, splited, quote-removed tokens and converts them into a
// t_tok array.
t_tok	*normalize(t_xtok *toks)
{
	t_tok	*cmd;

	cmd = NULL;
	lst
	while(toks)
	{
		cmd = tok_add(&cmd, xtok_totok(toks));
		
		toks = toks->nxt;
	}
}
