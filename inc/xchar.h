/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xchar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:13:46 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/27 18:40:33 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XCHAR_H
# define XCHAR_H

# include "list_utils.h"

typedef struct s_xchar
{
	char	c;
	int		x : 1;
	int		q : 2;
}	t_xchar;

int		xc_strcmp(char *str, t_lst *xstr);
t_lst	*xc_rm(t_lst **lst, t_lst *to_rm);

#endif