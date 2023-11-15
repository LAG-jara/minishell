/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xchar.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:23:56 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/15 17:39:25 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XCHAR_H
# define XCHAR_H

# include "list.h"

# define UNEXPANDED 0
# define EXPANDED 1

// An xchar associates a char with a couple of flags to indicate its quote
// status ('q') and if it resulted from an expansion ('x').
typedef struct s_xchar
{
	char			c;
	unsigned int	x : 1;
	unsigned int	q : 2;
}	t_xchar;

t_xchar		xc_new(char c, int x_flag, int q_flag);
t_xchar		xc_get(t_list *node);
char		*xclst_to_str(t_list *xclst);
t_list		*str_to_xclst(const char *str, int x_flag, int q_flag);

#endif
