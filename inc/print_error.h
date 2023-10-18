/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:04:05 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/18 13:45:47 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ERROR_H
# define PRINT_ERROR_H

# define ERRMSG_SYNTAX "syntax error near token"
# define ERRNO_SYNTAX 258

# include "minish_consts.h"
# include <stdio.h>

int	print_err_syntax(char *token, int ret);

#endif