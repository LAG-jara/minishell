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
t_xtoken	*xtok_rm(t_xtoken **xtok, t_xtoken *to_rm)
{
	lst_rm(xtok, to_rm, free);
}
