/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtok_add_many.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:33:07 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/31 18:37:44 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Adds the 'to_add' xchar list nodes right before the 'pos' position at 'xtok'.
void	xtok_add_many(t_xtoken *xtok, t_list *pos, t_list *to_add)
{
	lst_add_many(&(xtok->val), pos, to_add);
}
