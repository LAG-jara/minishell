/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtoklst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:24:13 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/02 11:24:15 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"

void	xtoklst_clear(t_list **xtoks)
{
	// TODO: mirar si es correcto
	lst_clear(xtoks, free);
}