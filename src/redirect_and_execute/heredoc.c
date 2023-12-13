/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:03:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/13 18:36:20 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "print_error.h"
#include "signal_handler.h"
#include "readline/readline.h"

// Removes the temporary here document file.
void	clear_heredoc(void)
{
	unlink(HEREDOC_FILENAME);
}

static void set_heredoc_sig(void)
{
	init_signals(HEREDOC);
	// signal(SIGINT, SIG_DFL);
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
	while (1)
	{
		set_heredoc_sig();
		// ignore_signal(SIGQUIT);
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

// Links the read here document to the standard input.
// If 'expand' is TRUE, expands the environment variables of its content.
// Returns the appropriate exit code after printing any error message.
int	link_heredoc(void)
{
	int	fd_file;
	int	err;

	fd_file = open_file(HEREDOC_FILENAME, O_RDONLY);
	if (fd_file == -1)
		return (print_err_heredoc());
	err = dup2(fd_file, STDIN_FILENO);
	if (!err)
		err = close(fd_file);
	if (err)
		return (print_err_heredoc());
	return (EXIT_SUCCESS);
}
