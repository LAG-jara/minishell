/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtok_addxc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:57:32 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/02 16:59:03 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

// Adds 'xc' at the end of 'xtok'.
void	xtok_addxc(t_xtoken *xtok, t_xchar xc)
{
	lst_add(&(xtok->val), lst_new(&xc, sizeof(xc)));
}
