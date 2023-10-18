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

#ifndef STRARR_UTILS_H
# define STRARR_UTILS_H

# include "basic_utils.h"

// 2-Dimensional String Arrays

char	**strarr2_add_subarr_at(char **arr, char **subarr, int i);
char	**strarr2_add(char **arr, char *str);
char	**strarr2_dup(char **arr);
void	strarr2_free(char **arr);
size_t	strarr2_get_size(char **arr);
char	**strarr2_rm(char **arr, int i);
char	**strarr2_set(char **arr, char *str, int index);

// 3-Dimensional String Arrays

char	**strarr3_add(char ***arr, char **subarr);
char	**strarr3_dup(char ***arr);
void	strarr3_free(char ***arr);
size_t	strarr3_get_size(char ***arr);
char	**strarr3_set(char ***arr, char **subarr, int i);

#endif