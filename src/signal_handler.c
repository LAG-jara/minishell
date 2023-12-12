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

#define READLINE_LIBRARY

# include "../readline/readline.h"
# include "../readline/history.h"

static void	norm_handler(int sig, siginfo_t *data, void *non_used_data)
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

static void	heredoc_handler(int sig, siginfo_t *data, void *non_used_data)
{
	(void) data;
	(void) non_used_data;
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
		exit(1);
	}
	return ;
}

static void	ninter_handler(int sig, siginfo_t *data, void *non_used_data)
{
	(void) data;
	(void) non_used_data;
	if (sig == SIGINT)
		exit(130);
	else if (sig == SIGQUIT)
		exit(131);
	return ;
}

int	init_signals(int mode)
{
	struct sigaction	signal;

	signal.sa_flags = SA_RESTART;
	sigemptyset(&signal.sa_mask);
	if (mode == INTER)
		signal.sa_sigaction = norm_handler;
	if (mode == NON_INTER)
		signal.sa_sigaction = ninter_handler;
	if (mode == HEREDOC)
		signal.sa_sigaction = heredoc_handler;
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



// Normal mode signal
// void	signal_handler(int signal)
// {
// 	if (signal == SIGINT)
// 	{
// 		rl_replace_line("", signal);
// 		printf("\n");
// 		rl_on_new_line();
// 		rl_redisplay();
// 	}
// }
