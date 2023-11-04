/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:00:00 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 14:24:20 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_error.h"

// Prints the a syntax error message regarding 'token' and returns the
// corresponding exit code.
int	print_err_syntax(char *token)
{
	printf("%s: %s '%s'\n", SH_NAME, MSG_SYNTERR, token);
	return (EXIT_SYNTERR);
}

// Prints the an error message regarding a wrong arguments amount and returns
// tho corresponding exit code.
int	print_err_argc()
{
	printf("%s: %s\n", SH_NAME, MSG_WRONGAC);
	return (EXIT_WRONGAC);
}
