/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtoken.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:13:46 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/30 11:53:04 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XTOKEN_H
# define XTOKEN_H

# include "list_utils.h"
# include "token_utils.h"

// An xchar associates a char with a couple of flags to indicate if its quote
// status ('q') and if it resulted from an expansion ('x').
typedef struct s_xchar
{
	char			c;
	unsigned int	x : 1;
	unsigned int	q : 2;
}	t_xchar;

// TODO: Add description
typedef struct s_xtoken
{
	t_list			*val;
	unsigned int	type : 2;
}	t_xtoken;

t_xchar		xc_new(char c, int x_flag, int q_flag);
void		xtok_addc(t_xtoken *xtok, char c, int x_flag, int q_flag);
void		xtok_adds(t_xtoken *xtok, char *str, int x_flag, int q_flag);
void		xtok_addxc(t_xtoken *xtok, t_xchar xc);
void		xtok_set_type(t_xtoken *xtok, int type);
void		xtok_rm(t_xtoken *xtok, t_xchar *to_rm);
t_token		xtok_to_tok(t_xtoken *xtok);
t_xtoken	tok_to_xtok(t_token *tok);

#endif