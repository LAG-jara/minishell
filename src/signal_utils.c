/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:50:54 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/18 14:14:45 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "signal_utils.h"
#include "readline.h"
#include "history.h"
#include <signal.h>
#include <termios.h>
#include "boolean.h"

static void	inter_handler(int sig)
{
	g_signal = sig;
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	heredoc_handler(int sig)
{
	g_signal = sig;
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("\0", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

// Set the signal handling of the loop during the parse
// void set_interactive_sig(void)
// {
// 	g_signal = 0;
// 	init_signals(INTER);
// 	signal(SIGQUIT, SIG_IGN);
// 	signals_print_handler(FALSE);
// }

// int	init_signals(int mode)
// {
// 	struct sigaction	signal;

// 	signal.sa_flags = SA_RESTART;
// 	sigemptyset(&signal.sa_mask);
// 	if (mode == INTER)
// 		signal.sa_sigaction = inter_handler;
// 	if (mode == NON_INTER)
// 		signal.sa_handler = SIG_DFL;
// 	sigaction(SIGINT, &signal, NULL);
// 	sigaction(SIGQUIT, &signal, NULL);
// 	return (0);
// }

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

void	set_signals(int mode)
{
	if (mode == INTER)
	{
		g_signal = 0;
		signal(SIGINT, inter_handler);
		signal(SIGQUIT, SIG_IGN);
		signals_print_handler(FALSE);
	}
	if (mode == HEREDOC)
	{
		signal(SIGINT, heredoc_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	if (mode == NON_INTER)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		signals_print_handler(TRUE);
	}
}