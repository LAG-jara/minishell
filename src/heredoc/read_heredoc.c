/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:03:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 20:03:33 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_private.h"
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include "basic_utils.h"
#include "input_utils.h"
#include "open_file.h"
#include "readline/readline.h"

// Sets the signal handlers for the here document.
static void set_heredoc_sig(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
}

// Creates a here document, reading the standard input until 'delim'.
// If 'expand' is TRUE, the variable names are expanded.
// Returns 0 on success, or -1 in case of failure (setting errno).
int	read_heredoc(const char *delim, int expand, char **env)
{
	int		fd_file;
	char	*line;
	char	*tmp;

	fd_file = open_file(HEREDOC_FILENAME, O_CREAT | O_WRONLY | O_TRUNC);
	if (fd_file == -1)
		return (-1);
	set_heredoc_sig();
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			ft_putstr_fd("\033[A\033[2K> ", STDOUT_FILENO);
		if (line == NULL || !ft_strncmp(line, delim, ft_strlen(delim) + 1))
			break ;
		if (expand)
		{
			tmp = expand_vars(line, env);
			free(line);
			line = tmp;
		}
		ft_putendl_fd(line, fd_file);
	}
	return (close(fd_file));
}
