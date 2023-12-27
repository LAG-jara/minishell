/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:04:05 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/27 17:37:14 by glajara-         ###   ########.fr       */
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
# define MSG_PERM_DENIED	"Permission denied"
# define EXIT_PERM_DENIED	126
# define MSG_IS_DIR			"is a directory"
# define EXIT_IS_DIR		126
# define MSG_NOFILE			"No such file or directory"
# define EXIT_NOFILE		127
# define MSG_AMBIG_REDIR	"ambiguous redirect"
# define EXIT_AMBIG_REDIR	1
# define MSG_PIPE_ERR		"pipe error"
# define EXIT_PIPE_ERR		1
# define MSG_HEREDOC_ERR	"cannot create temp file for here document"

// BUILTIN

# define MSG_NUMARG 		"numeric argument required"
# define EXIT_NUMARG 		255
# define MSG_IDENTERR 		"not a valid identifier"

int		print_err_syntax(const char *token, int ret);
int		print_err_argc(void);
void	print_err_filename(const char *filename);
void	print_err_pipe(void);
int		print_err_heredoc(int ret);

// BUILTIN ERRORS

int		print_err_identifier(const char *identifier, const char *builtin);
int		print_err_too_many_arg(void);
int		print_err_numeric_arg(const char *arg);
int		print_err_builtin(const char *builtin, const char *arg);

// EXEC ERRORS

void	print_err_exec(const char *cmdname);
void	print_err_nofile(const char *cmdname);
void	print_err_cmd_not_found(const char *cmdname);
void	print_err_perm_denied(const char *cmdname);
void	print_err_isdir(const char *path);
void	print_err_redir(void);

#endif