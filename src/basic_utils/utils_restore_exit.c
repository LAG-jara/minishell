/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_restore_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:59:00 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/18 18:08:24 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boolean.h"
#include "signal_utils.h"
#include <stdlib.h>

// Restores the default print signal config and exits returning 'exit_status'.
void	restore_exit(int exit_status)
{
	signals_print_handler(TRUE);
	exit(exit_status);
}
