/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:04:08 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/17 19:02:53 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRSTR_UTILS_H
# define ARRSTR_UTILS_H

# include "basic_utils.h"

// 2-Dimensional String Arrays

char	**arrstr_fill_idx(char **arr, char **subarr, int i);
char	**arrstr_add(char **arr, char *str);
char	**arrstr_dup(char **arr);
void	arrstr_free(char **arr);
size_t	arrstr_get_size(char **arr);
char	**arrstr_rm(char **arr, int i);
char	**arrstr_set(char **arr, char *str, int index);

// 3-Dimensional String Arrays

char	***aarrstr_add(char ***arr, char **subarr);
char	***aarrstr_dup(char ***arr);
void	aarrstr_free(char ***arr);
size_t	aarrstr_get_size(char ***arr);
char	***aarrstr_set(char ***arr, char **subarr, int i);

#endif