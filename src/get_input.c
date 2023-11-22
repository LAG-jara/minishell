/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:58:36 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/22 15:24:26 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_input.h"

// Prints the prompt and waits for user input (managing the history).
// Allocates and returns the string provided by the user.
char	*get_input(void)
{
	char	*str;

	str = readline(PROMPT);
	if (str && *str)
		add_history(str);
	return (str);
}


// int main()
// {
// 	while (42)
// 	{
// 		char *str = readline(PROMPT);
// 		printf("I got: %s\n", str);
// 	}
// }
