/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtoken.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:13:46 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/14 16:49:28 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XTOKEN_H
# define XTOKEN_H

# include "token.h"
# include "xchar.h"

// A stoken can be of type word, redirection, pipe or invalid.
// It's value is defined as a list of xchars, with quote and expansion flags.
typedef struct s_xtoken
{
	t_list			*val;
	unsigned int	type : 2;
}	t_xtoken;

t_xtoken	*xtok_get(t_list *node);
void		xtok_add_many(t_xtoken *xtok, t_list *pos, t_list *to_add);
void		xtok_addc(t_xtoken *xtok, char c, int x_flag, int q_flag);
void		xtok_addxc(t_xtoken *xtok, t_xchar xc);
void		xtok_rm_one(t_xtoken *xtok, t_list *to_rm);
void		xtok_rm_many(t_xtoken *xtok, t_list *to_rm, size_t n);
void		xtok_rm_xcs(t_xtoken *xtok, t_xchar *to_rm);
t_token		xtok_to_tok(t_xtoken *xtok);
t_xtoken	tok_to_xtok(t_token *tok);
void		xtoklst_clear(t_list **xtoks);
int			xtok_strncmp(t_xtoken *xtok, const char *str, size_t n);

#endif