/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:50:54 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/13 17:27:31 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handler.h"
#include "../readline/readline.h"
#include "../readline/history.h"

static void	inter_handler(int sig, siginfo_t *data, void *non_used_data)
{
	(void) data;
	(void) non_used_data;
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}

int	init_signals(int mode)
{
	struct sigaction	signal;

	signal.sa_flags = SA_RESTART;
	sigemptyset(&signal.sa_mask);
	if (mode == INTER)
		signal.sa_sigaction = inter_handler;
	if (mode == NON_INTER)
		signal.sa_handler = SIG_DFL;
	sigaction(SIGINT, &signal, NULL);
	sigaction(SIGQUIT, &signal, NULL);
	return (0);
}

void	ignore_signal(int signum)
{
	struct sigaction	signal;

	signal.sa_handler = SIG_IGN;
	signal.sa_flags = SA_RESTART;
	sigemptyset(&signal.sa_mask);
	if (sigaction(signum, &signal, NULL) < 0)
		exit (1);
}
