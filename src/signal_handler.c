/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:50:54 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/23 17:50:56 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handler.h"

 static void	process(int sign_num)
{
	if (!kill(g_pid, sign_num))
	{
		if (sign_num == SIGTERM)
		{
			ft_putstr_fd("Exit\n", 1);
			g_status = 131;
		}
		else if (sign_num == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_status = 130;
		}
	}
	else if (sign_num == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		g_status = 1;
		prompt();
	}
}

void	signal_handler(int sign_num)
{
	if ((sign_num == SIGINT || sign_num == SIGTERM) && g_pid != 0)
		process(sign_num);
	else
	{
		if (sign_num == SIGINT)
		{
			ft_putchar_fd('\n', 1);
			g_status = 1;
			prompt();
		}
		else if (sign_num == SIGTERM)
			ft_putstr_fd("\b\b  \b\b", 1);
	}
}
