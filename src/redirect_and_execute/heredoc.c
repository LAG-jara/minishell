/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:03:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/16 14:19:25 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"
#include "print_error.h"

// Removes the temporary here document file.
void	clear_heredoc(void)
{
	unlink(HEREDOC_FILENAME);
}

// Returns TRUE if 'str' is the delimeter, FALSE otherwise.
// Works exactly as in the HereDoc.
static int	is_delimeter(const char *str, const char *delimeter)
{
	int	len;

	len = ft_strlen(delimeter);
	if (ft_strncmp(str, delimeter, len) == 0 && str[len] == '\n')
		return (TRUE);
	return (FALSE);
}

// Creates a here document, reading the standard input until 'delimiter'.
// If 'expand' is TRUE, the variable names are expanded.
// Returns 0 on success, or -1 in case of failure (setting errno).
static int	read_heredoc(const char *delimiter, const int expand, char **env)
{
	int		fd_file;
	char	*line;
	char	*tmp;

	fd_file = open_file(HEREDOC_FILENAME, O_CREAT | O_WRONLY | O_TRUNC);
	if (fd_file == -1)
		return (-1);
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);			// TODO: use readline() ?
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			exit(EXIT_FAILURE);
		if (is_delimeter(line, delimiter))
			break ;
		if (expand)
		{
			tmp = expand_vars(line, env);
			free(line);
			line = tmp;
		}
		ft_putstr_fd(line, fd_file);
	}
	return (close(fd_file));
}

// Opens a here document and links it to the standard input.
// If 'expand' is TRUE, expands the environment variables of its content.
// Returns the appropriate exit code after printing any error message.
int	link_heredoc(const char *delimeter, const int expand, char **env)
{
	int	fd_file;
	int	err;

	err = read_heredoc(delimeter, expand, env);
	if (err)
		return (print_err_heredoc());
	fd_file = open_file(HEREDOC_FILENAME, O_RDONLY);
	if (fd_file == -1)
		return (print_err_heredoc());
	dup2(fd_file, STDIN_FILENO);
	if (!err)
		err = close(fd_file);
	if (err)
		return (print_err_heredoc());
	return (EXIT_SUCCESS);
}
