/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:02:33 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:24:19 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_UTILS_H
# define INPUT_UTILS_H

int	is_blankchr(int c);
int	is_metachr(int c);
int	is_operatorchr(int c);
int	is_redirectionchr(int c);
int	is_quotechr(int c);
int	is_word(const char *str);

#endif