/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:40:39 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/14 17:11:59 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns 1 if 'c' is a white-space character, 0 otherwise.
int	ft_isspace(unsigned char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

// Returns 1 if 'c' is an alphabetic character, 0 otherwise.
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// Returns 1 if 'c' is a decimal digit character, 0 otherwise.
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// Returns 1 if 'c' is an alphanumeric character, 0 otherwise.
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
