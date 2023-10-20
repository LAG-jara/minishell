/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:21:35 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/20 12:49:09 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTE_UTILS_H
# define QUOTE_UTILS_H

# define UNQUOTED 0
# define QUOTED 1
# define DQUOTED 2

int	update_quote_status(int curr_status, char c);
int	quote_skip(char *in, int i);

#endif