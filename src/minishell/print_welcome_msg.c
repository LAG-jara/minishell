/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_welcome_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:28:03 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/20 17:57:19 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include "minish_consts.h"
#include <unistd.h>

// Prints the minish welcome message to the standard output.
void	print_welcome_msg(void)
{
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_putstr_fd(TRIFORCE_1, STDOUT_FILENO);
	ft_putendl_fd(LINE_1, STDOUT_FILENO);
	ft_putstr_fd(TRIFORCE_2, STDOUT_FILENO);
	ft_putendl_fd(LINE_2, STDOUT_FILENO);
	ft_putendl_fd(LINE_3, STDOUT_FILENO);
	ft_putendl_fd(LINE_4, STDOUT_FILENO);
}
