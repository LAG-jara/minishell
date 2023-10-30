/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtok_rmc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:41:11 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/27 18:58:36 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Removes and frees the given 'to_rm' xchar from the 'xtok'.
void	xtok_rm(t_xtoken *xtok, t_xchar *to_rm)
{
	lst_rm_one(xtok->val, to_rm, free);
}
