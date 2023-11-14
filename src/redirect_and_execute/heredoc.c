/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:03:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/14 15:34:04 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

// Returns TRUE if 'str' is the delimeter, FALSE otherwise.
// Works exactly as in the HereDoc.
static int	is_delimeter(char *str, char *delimeter)
{
	int	delimeter_len;

	delimeter_len = ft_strlen(delimeter);
	if (ft_strncmp(str, delimeter, delimeter_len) == 0
		&& str[delimeter_len] == '\n'
	)
		return (TRUE);
	return (FALSE);
}

// Opens a here document and links it to the standard input.
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

// Assuming the file named as the global HEREDOC_FILENAME exists, rewrites its
// content expanding the enviroment $VARIABLES.
static void	expand_file_vars(char **env)
{
	int		fd_file;
	char	*line;
	char	*old_content;
	char	*new_content;

	old_content = ft_strdup("");
	fd_file = open_file(HEREDOC_FILENAME, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd_file);
		if (line == NULL)
			break ;
		gnl_strjoin_free(&old_content, line);
		free(line);
	}
	close(fd_file);
	new_content = expand_vars(old_content, env);
	fd_file = open_file(HEREDOC_FILENAME, O_CREAT | O_WRONLY | O_TRUNC);
	if (write(fd_file, new_content, ft_strlen(new_content)) <= 0)
		exit(EXIT_FAILURE);
	close(fd_file);
}

// Opens a here document, reads it until 'delimiter' and returns its file
// descriptor. If 'expand' is TRUE, the variable names are expanded.
int	read_heredoc(char *delimiter, int expand, char **env)
{
	int		fd_file;
	char	*line;
	char	tmp;

	fd_file = open_file(HEREDOC_FILENAME, O_CREAT | O_WRONLY | O_TRUNC);
	while (1)
	{
		write(STDOUT_FILENO, ">", 9);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			exit(EXIT_FAILURE);
		if (is_delimeter(line, delimiter))
			break ;
		ft_putstr_fd(line, fd_file);
	}
	close(fd_file);
	if (expand)
		expand_file_vars(env);
	fd_file = open_file(HEREDOC_FILENAME, O_RDONLY);
	return (fd_file);
}
