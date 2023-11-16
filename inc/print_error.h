/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:04:05 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/16 15:31:18 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ERROR_H
# define PRINT_ERROR_H

# define MSG_SYNTERR 		"syntax error near token"
# define EXIT_SYNTERR 		258
# define MSG_WRONGAC 		"wrong arguments amount"
# define EXIT_WRONGAC 		2
# define MSG_CMD_NOT_FOUND	"command not found"
# define EXIT_CMD_NOT_FOUND	127
# define MSG_HEREDOC_ERR	"here document error"

# include "basic_utils.h"
# include "minish_consts.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>

int		print_err_syntax(const char *token, int ret);
int 	print_err_argc();
void	print_err_exec(const char *cmdname);
void	print_err_filename(const char *filename);
int		print_err_heredoc();

#endif