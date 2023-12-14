/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:37:42 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:02:45 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_UTILS_H
# define BASIC_UTILS_H

# include "boolean.h"
# include <stdlib.h>

// Characters

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isspace(int c);

// Strings

int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *str, char c);
char		**ft_split(const char *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_strjoin_free(char **s1, const char *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
long long	ft_atoll(char *str);

// Other

void		restore_exit(int exit_status);
void		*p_malloc(size_t size);
char		*ft_itoa(int n);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(const char *s, int fd);
size_t		arr_size(void **arr);

#endif
