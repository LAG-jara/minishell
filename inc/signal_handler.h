/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:50:25 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/23 17:50:31 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

// MODES OF SETTING SIGNALS

# define INTER 1
# define NON_INTER -1
# define HEREDOC 42

int		init_signals(int mode);
void	ignore_signal(int signum);

#endif
