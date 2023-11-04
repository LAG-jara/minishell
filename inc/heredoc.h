/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:19:43 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/01 15:00:35 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# define HEREDOC_FILENAME ".heredoc_temp"

# include "get_next_line.h"
# include "libft.h"
# include "open_file.h"
# include "expand_vars.h"

void	link_heredoc(char *delimeter, int expand, char **env);
int		read_heredoc(char *delimiter, int expand, char **env);
void	clear_heredoc(void);

#endif