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
# include "readline/readline.h"
# include "readline/history.h"

// Normal mode signal
void	signal_handler(int signal)
{
	signal+=0;
	//rl_replace_line("", signal);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}
