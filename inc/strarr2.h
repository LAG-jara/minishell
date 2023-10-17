/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarr2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:04:08 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/17 19:02:53 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRARR2_H
# define STRARR2_H

# include "basic_utils.h"

// 2-Dimensional String Arrays

size_t	get_strarr2_size(char **arr);
char	**dup_strarr2(char **arr);
char	**set_strarr2(char **arr, char *str, int index);
char	**add_strarr2(char **arr, char *str);
char	**rm_strarr2(char **arr, int i);
char	**add_subarr_at_strarr2(char **arr, char **subarr, int i);
void	free_strarr2(char **arr);

// 3-Dimensional String Arrays

void	free_strarr3(char ***arr);

#endif