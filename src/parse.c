/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:09:34 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/14 17:06:40 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "utils.h"
#include "env.h"

// Returns the amount of commands in the NULL-terminated 'tokens' array.
// If a syntax error is found, prints an error message and returns NULL.
int	count_commands(char **tokens, char ***env)
{
	
}

// Parses the NULL-terminated array of tokens and groups them into a 
// NULL-terminated array of commands, dividing them by the single token '|'
// If a syntax error is found, prints an error message, the environment variable
// $? is set to the exit status of the last executed command and returns NULL.
char	***parse(char **tokens, char ***env)
{
	int		cmd_amount;
	char	*err_msg;	

	cmd_amount = count_commands(tokens, env);
	if (cmd_amount == -1)
		return (NULL);


}