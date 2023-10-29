/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtoken.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:13:46 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/29 13:03:41 by glajara-         ###   ########.fr       */
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

void	xc_set_flags(int exp_stat, int quote_stat);
int		xtok_cmp(char *str, t_lst *xstr);
t_lst	*xtok_rmc(t_lst **xtok, t_lst *to_rm);
t_lst	*xtok_addc(t_lst **xtok, char c);
t_lst	*xtok_adds(t_lst **xtok, char *c);
char	*xtok_tostr(t_lst **xtok);

#endif