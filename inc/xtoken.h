/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xchar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:13:46 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/27 19:11:02 by glajara-         ###   ########.fr       */
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

int		xc_strcmp(char *str, t_lst *xstr);
t_lst	*xc_rm(t_lst **lst, t_lst *to_rm);
void	xc_set_flags(int exp_stat, int quote_stat);

#endif