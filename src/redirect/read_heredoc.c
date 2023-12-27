/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:03:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/27 17:38:50 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_private.h"
#include <fcntl.h>
#include <unistd.h>
#include "basic_utils.h"
#include "input_utils.h"
#include "open_file.h"
#include <stdio.h>
#include "readline.h"
#include "signal_utils.h"
#include "print_error.h"

// Creates a here document, reading the standard input until 'd' is found and
// saving the content into the specified temp 'file'.
// If 'x' is TRUE, the variable names are expanded.
// Exits with 0 on success, 1 on SIGINT received, or -1 in case of failure.
static int	read_hd_child(const char *d, int x, const char *file, char **env)
{
	int		fd_file;
	char	*line;
	char	*tmp;

	set_signals(HEREDOC);
	fd_file = open_file(file, O_CREAT | O_WRONLY | O_TRUNC);
	if (fd_file == -1)
		return (print_err_heredoc(EXIT_FAILURE));
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			ft_putstr_fd("\033[A\033[2K> ", STDOUT_FILENO);
		if (line == NULL || !ft_strncmp(line, d, ft_strlen(d) + 1))
			break ;
		if (x)
		{
			tmp = expand_vars(line, env);
			free(line);
			line = tmp;
		}
		ft_putendl_fd(line, fd_file);
	}
	exit(close(fd_file));
}

// Creates a here document, reading the standard input until 'delim' is found
// and saving the content into the specified temp 'file'.
// If 'exp' is TRUE, the variable names are expanded.
// Returns 0 on success, 1 on SIGINT received, or -1 in case of failure.
int	read_heredoc(const char *delim, int exp, const char *file, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		exit (EXIT_FAILURE);
	if (pid == 0)
		read_hd_child(delim, exp, file, env);
	wait(&status);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status) && (WTERMSIG(status) == SIGINT))
		return (EXIT_FAILURE);
	return (EXIT_FAILURE);
}
