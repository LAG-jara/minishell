/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrstr.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:04:08 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/17 19:02:53 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRSTR_H
# define ARRSTR_H

# include <unistd.h>

char	**arrstr_add(char **arr, const char *str);
char	**arrstr_dup(char **arr);
void	arrstr_free(char **arr);
size_t	arrstr_size(char **arr);
char	**arrstr_rm(char **arr, int i);
char	**arrstr_set(char **arr, const char *str, int index);

#endif
