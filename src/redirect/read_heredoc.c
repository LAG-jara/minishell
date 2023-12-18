/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:03:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/18 14:01:34 by glajara-         ###   ########.fr       */
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

// Returns 1 after closing fd_file.
int	cancel_heredoc(int fd_file)
{
	close(fd_file);
	return (1);
}

// Creates a here document, reading the standard input until 'delim' is found
// and saving the content into the specified temp 'file'.
// If 'exp' is TRUE, the variable names are expanded.
// Returns 0 on success, 1 on SIGINT received, or -1 in case of failure
// (setting errno).
int	read_heredoc(const char *delim, int exp, const char *file, char **env)
{
	int		fd_file;
	char	*line;
	char	*tmp;

	fd_file = open_file(file, O_CREAT | O_WRONLY | O_TRUNC);
	if (fd_file == -1)
		return (-1);
	while (1)
	{
		line = readline("> ");
		if (g_signal == SIGINT)
			return (cancel_heredoc(fd_file));
		if (line == NULL)
			ft_putstr_fd("\033[A\033[2K> ", STDOUT_FILENO);
		if (line == NULL || !ft_strncmp(line, delim, ft_strlen(delim) + 1))
			break ;
		if (exp)
		{
			tmp = expand_vars(line, env);
			free(line);
			line = tmp;
		}
		ft_putendl_fd(line, fd_file);
	}
	return (close(fd_file));
}
