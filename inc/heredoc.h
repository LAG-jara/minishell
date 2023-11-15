/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:19:43 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/15 17:20:22 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# define HEREDOC_FILENAME "/tmp/heredoc_temp"

# include "definitions.h"
# include "expand_vars.h"
# include "get_next_line.h"
# include "list.h"
# include "open_file.h"
# include "quote_utils.h"

void	link_heredoc(char *delimeter, int expand, char **env);
int		read_heredoc(char *delimiter, int expand, char **env);
void	clear_heredoc(void);

int		delim_quote_remove(char **str);

#endif