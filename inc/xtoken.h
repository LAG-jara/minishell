/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtoken.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:13:46 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/01 10:10:33 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XTOKEN_H
# define XTOKEN_H

# include "list.h"
# include "token_utils.h"

// An xchar associates a char with a couple of flags to indicate if its quote
// status ('q') and if it resulted from an expansion ('x').
typedef struct s_xchar
{
	char			c;
	unsigned int	x : 1;
	unsigned int	q : 2;
}	t_xchar;

// A stoken can be of type word, redirection, pipe or invalid.
// It's value is defined as a list of xchars, with quote and expansion flags.
typedef struct s_xtoken
{
	t_list			*val;
	unsigned int	type : 2;
}	t_xtoken;

t_xchar		xc_new(char c, int x_flag, int q_flag);
t_xchar		xc_get(t_list *node);
char		*xclst_to_str(t_list *xclst);
t_list		*str_to_xclst(char *str, int x_flag, int q_flag);
void		xtok_add_many(t_xtoken *xtok, t_list *pos, t_list *to_add);
void		xtok_addc(t_xtoken *xtok, char c, int x_flag, int q_flag);
void		xtok_rm_one(t_xtoken *xtok, t_list *to_rm);
void		xtok_rm_many(t_xtoken *xtok, t_list *to_rm, size_t n);
void		xtok_rm_xcs(t_xtoken *xtok, t_xchar *to_rm);
t_token		xtok_to_tok(t_xtoken *xtok);
t_xtoken	tok_to_xtok(t_token *tok);

// DEPRECATED ?
// void		xtok_adds(t_xtoken *xtok, char *str, int x_flag, int q_flag);
#endif