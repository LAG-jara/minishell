/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_to_xtok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:56:28 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/31 12:00:30 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Converts the given token to a xtoken, keeping the token type and setting the
// appropiate xchar flags.
t_xtoken	tok_to_xtok(t_token *tok)
{
	t_xtoken	xtok;
	char		*str;
	int			q_stat;

	xtok.type = tok->type;
	xtok.val = NULL;
	q_stat = UNQUOTED;
	str = tok->val;
	while (*str)
	{
		q_stat = quote_stat_pre(q_stat, *str);
		xtok_addc(&xtok, *str, UNEXPANDED, q_stat);
		q_stat = quote_stat_post(q_stat, *str);
		++str;
	}
	return (xtok);
}
