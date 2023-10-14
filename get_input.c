/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:58:36 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/14 15:07:37 by glajara-         ###   ########.fr       */
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

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	*input;

// 	while (42)
// 	{
// 		input = get_input();
// 		printf("got: %s\n", input);
// 		if (strcmp(input, "exit") == 0)
// 			return (1);
// 	}
// }
