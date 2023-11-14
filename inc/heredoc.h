/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:19:43 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/14 15:23:12 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# define HEREDOC_FILENAME "/tmp/heredoc_temp"

// # include "expand_vars.h"
// # include "get_next_line.h"
// # include "libft.h"
# include "open_file.h"
# include "definitions.h"
# include "quote_utils.h"
# include "list.h"

void	link_heredoc(char *delimeter, int expand, char **env);
int		read_heredoc(char *delimiter, int expand, char **env);
void	clear_heredoc(void);

int		quote_remove_delimeter(char **str);

#endif