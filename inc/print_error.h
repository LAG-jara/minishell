/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:04:05 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 14:43:34 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ERROR_H
# define PRINT_ERROR_H

# define MSG_SYNTERR "syntax error near token"
# define EXIT_SYNTERR 258
# define MSG_WRONGAC "wrong arguments amount"
# define EXIT_WRONGAC 2

# include "minish_consts.h"
# include <stdio.h>

int	print_err_syntax(char *token, int ret);
int print_err_argc();

#endif