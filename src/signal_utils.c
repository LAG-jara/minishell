/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:50:54 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/14 16:56:51 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_utils.h"
#include "../readline/readline.h"
#include "../readline/history.h"

static void	inter_handler(int sig, siginfo_t *data, void *non_used_data)
{
	(void) data;
	(void) non_used_data;
	g_signal = sig;
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}

// Set the signal handling of the loop during the parse
void set_interactive_sig(void)
{
	g_signal = 0;
	init_signals(INTER);
	signal(SIGQUIT, SIG_IGN);
	signals_print_handler(FALSE);
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

// If print is TRUE signals will be printed, otherwise they won't. 
void	signals_print_handler(int print)
{
	struct termios	tc;

	tcgetattr(0, &tc);
	tc.c_lflag &= ~ECHOCTL;
	if (print == TRUE)
		tc.c_lflag |= ECHOCTL;
	tcsetattr(0, TCSANOW, &tc);
}

void	stop_signals()
{
	signal(SIGINT, SIG_IGN);			// TODO: stop_signals() ?
	signal(SIGQUIT, SIG_IGN);
}
