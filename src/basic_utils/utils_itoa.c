/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:29:39 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 12:41:52 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"

// Return the amount of digits needed to represent n in decimal (including
// sign, if needed).
static int	digit_count(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		digits++;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

// Allocates (with malloc(3)) and returns a string representing the integer 
// received as an argument. Negative numbers must be handled.
// Exits properly if malloc fails.
char	*ft_itoa(int n)
{
	char	*str;
	int		strlen;

	strlen = digit_count(n);
	str = (char *)p_malloc((strlen + 1) * sizeof(char));
	str[strlen--] = '\0';
	if (n == 0)
		*str = '0';
	if (n < 0)
	{
		*str = '-';
		str[strlen--] = -(n % 10) + '0';
		n /= -10;
	}
	while (n != 0)
	{
		str[strlen--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
