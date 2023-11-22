/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtok_to_tok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:08:08 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/31 18:44:39 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Converts the given xtoken to a token, losing the xchar flags and keeping the
// token type.
t_token	xtok_to_tok(t_xtoken *xtok)
{
	t_token	tok;

	tok.type = xtok->type;
	tok.val = xclst_to_str(xtok->val);
	return (tok);
}
