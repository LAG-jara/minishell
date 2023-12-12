/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:04:05 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/12 16:05:23 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ERROR_H
# define PRINT_ERROR_H

# define MSG_SYNTERR		"syntax error near token"
# define EXIT_SYNTERR		258
# define MSG_WRONGAC		"minish does not accept arguments"
# define EXIT_WRONGAC		2
# define MSG_CMD_NOT_FOUND	"command not found"
# define EXIT_CMD_NOT_FOUND	127
# define MSG_HEREDOC_ERR	"here document error"
# define EXIT_NOPATH		127
# define MSG_NOPATH			"No such file or directory"


//BUITIN DEFINITIONS
# define MSG_NUMARG 		"numeric argument required"
# define EXIT_NUMARG 		255
//# define MSG_MANY_ARGS 		"too many arguments"
# define MSG_IDENTERR 		"not a valid identifier"

# include "basic_utils.h"
# include "minish_consts.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>

int		print_err_syntax(const char *token, int ret);
int		print_err_argc(void);
void	print_err_filename(const char *filename);
int		print_err_heredoc(void);

// BUILTIN ERRORS

int		print_err_identifier(const char *identifier);
int		print_err_too_many_arg(void);
int		print_err_numeric_arg(const char *arg);

// EXEC ERRORS
void	print_err_exec(const char *cmdname);
void	print_err_nopath(const char *cmdname);

#endif