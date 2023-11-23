/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:19:43 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/23 19:07:09 by glajara-         ###   ########.fr       */
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
# include "input_utils.h"

int		link_heredoc(const char *delimeter, const int expand, char **env);
void	clear_heredoc(void);

int		has_quotes(const char *word);
void	delim_quote_remove(char **str);

#endif
