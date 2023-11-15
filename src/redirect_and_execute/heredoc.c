/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:03:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/15 17:27:42 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

// Returns TRUE if 'str' is the delimeter, FALSE otherwise.
// Works exactly as in the HereDoc.
static int	is_delimeter(char *str, char *delimeter)
{
	int	len;

	len = ft_strlen(delimeter);
	if (ft_strncmp(str, delimeter, len) == 0 && str[len] == '\n')
		return (TRUE);
	return (FALSE);
}

// Opens a here document and links it to the standard input.
// If 'expand' is TRUE, expands the environment variables of its content.
void	link_heredoc(char *delimeter, int expand, char **env)
{
	int	fd_file;

	fd_file = read_heredoc(delimeter, expand, env);
	dup2(fd_file, STDIN_FILENO);
	close(fd_file);
}

// Removes the temporary here document file.
void	clear_heredoc(void)
{
	unlink(HEREDOC_FILENAME);
}

// Opens a here document, reads it until 'delimiter' and returns its file
// descriptor. If 'expand' is TRUE, the variable names are expanded.
int	read_heredoc(char *delimiter, int expand, char **env)
{
	int		fd_file;
	char	*line;
	char	*tmp;

	fd_file = open_file(HEREDOC_FILENAME, O_CREAT | O_WRONLY | O_TRUNC);
	while (1)
	{
		write(STDOUT_FILENO, ">", 9);
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
	close(fd_file);
	fd_file = open_file(HEREDOC_FILENAME, O_RDONLY);
	return (fd_file);
}
