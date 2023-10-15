/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:37:42 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/15 16:18:25 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

// Characters

int		ft_isspace(unsigned char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);

// Strings

int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_strdup2(const char *str);
char	**ft_split(char const *s, char c);

// String Arrays

size_t	get_strarr2_size(char **arr);
char	**dup_strarr2(char **arr);
char	**set_strarr2(char **arr, char *str, int index);
char	**add_strarr2(char **arr, char *str);
char	**rm_strarr2(char **arr, int i);
void	free_strarr2(char **arr);
void	free_strarr3(char ***arr);

#endif
