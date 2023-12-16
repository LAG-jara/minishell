/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:50:25 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/14 18:59:09 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_UTILS_H
# define SIGNAL_UTILS_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include "boolean.h"

// MODES OF SETTING SIGNALS

# define INTER 1
# define NON_INTER -1

int		init_signals(int mode);
void	ignore_signal(int signum);
void	signals_print_handler(int foo);
void	set_interactive_sig(void);
void	stop_signals(void);

// GLOBAL VARIABLE

int 	g_signal;

#endif
