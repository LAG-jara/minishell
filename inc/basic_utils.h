/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:37:42 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 18:09:00 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_UTILS_H
# define BASIC_UTILS_H

# include <stdlib.h>

// Characters

int		ft_isspace(unsigned char c);		// unused
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);

// Strings

int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_strchr(char *str, char c);
char	**ft_split(char const *s, char c);

// Other

void	*p_malloc(size_t size);
char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

#endif
