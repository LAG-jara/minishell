/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_to_xtok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:56:28 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 16:50:18 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"
#include "quote_utils.h"

// Converts the given token to a xtoken, keeping the token type and setting the
// appropriate xchar flags.
t_xtoken	tok_to_xtok(t_token *tok)
{
	t_xtoken	xtok;
	char		*str;
	int			q_stat;
	int			char_stat;

	xtok.type = tok->type;
	xtok.val = NULL;
	q_stat = UNQUOTED;
	str = tok->val;
	while (*str)
	{
		char_stat = quote_stat(&q_stat, *str);
		xtok_addc(&xtok, *str, UNEXPANDED, char_stat);
		++str;
	}
	return (xtok);
}
