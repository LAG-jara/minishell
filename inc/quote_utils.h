/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:21:35 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 17:36:28 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_UTILS_H
# define QUOTE_UTILS_H

# include "is_expanded.h"

# define UNQUOTED 0
# define QUOTED 1
# define DQUOTED 2

int	quote_skip(char *in, int i);
int	upd_quote_stat(int curr_status, char c);
int	upd_quote_stat_exp(int curr_stat, char c, int *expanded, char i);

#endif