/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtoken.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:13:46 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/29 15:03:05 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XTOKEN_H
# define XTOKEN_H

# include "list_utils.h"

typedef struct s_xchar
{
	char			c;
	unsigned int	x : 1;
	unsigned int	q : 2;
}	t_xchar;

typedef t_lst t_xtok;

t_xchar	xc_new(char c, int x_flag, int q_stat);
t_xtok	*xtok_rm(t_xtok **xtok, t_lst *to_rm);
t_xtok	*xtok_addc(t_xtok **xtok, char c, int x_flag, int q_flag);
t_xtok	*xtok_adds(t_xtok **xtok, char *str, int x_flag, int q_flag);
t_xtok	*xtok_addxc(t_xtok **xtok, t_xchar xc);
char	*xtok_tostr(t_xtok *xtok);

// DEPRECATED
int		xtok_cmp(t_xtok *xtok, char *str);

#endif