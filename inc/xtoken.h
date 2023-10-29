/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtoken.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:13:46 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/29 16:11:23 by glajara-         ###   ########.fr       */
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
typedef struct s_xtok
{
	t_lst			*val;
	unsigned int	type : 2;
}	t_xtok;

t_xchar	xc_new(char c, int x_flag, int q_flag);
void	xtok_addc(t_xtok *xtok, char c, int x_flag, int q_flag);
void	xtok_adds(t_xtok *xtok, char *str, int x_flag, int q_flag);
void	xtok_addxc(t_xtok *xtok, t_xchar xc);
void	xtok_set_type(t_xtok *xtok, int type);
void	xtok_rm(t_xtok *xtok, t_xtok *to_rm);
t_token	xtok_totok(t_xtok *xtok);

// DEPRECATED
int		xtok_cmp(t_xtok *xtok, char *str);

#endif