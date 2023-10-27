/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xc_rm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:41:11 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/27 18:58:36 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xchar.h"

// Removes and frees the given 'to_rm' xchar from the 'xstr'.
t_lst	*xc_rm(t_lst **xstr, t_lst *to_rm)
{
	lst_rm(xstr, to_rm, free);
}
