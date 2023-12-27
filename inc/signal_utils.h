/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:50:25 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/21 11:16:40 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_UTILS_H
# define SIGNAL_UTILS_H

// MODES OF SETTING SIGNALS

# define INTER 1
# define NON_INTER -1
# define HEREDOC 0

void	set_signals(int mode);
void	ignore_signal(int signum);
void	signals_print_handler(int foo);
void	set_interactive_sig(void);
void	stop_signals(void);

// Number of the received signal.
int		g_signal;

#endif
