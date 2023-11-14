/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:04:59 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 18:06:44 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include "unistd.h"

// Outputs the string ’s’ to the given file descriptor.
void	ft_putstr_fd(char *s, int fd)
{
	size_t	slen;

	if (!s)
		return ;
	slen = ft_strlen(s);
	write(fd, s, slen);
}

// Outputs the string ’s’ to the given file descriptor followed by a newline.
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
