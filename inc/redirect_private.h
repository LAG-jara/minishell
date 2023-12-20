/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:16:17 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/20 13:10:49 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_PRIVATE_H
# define REDIRECT_PRIVATE_H

# define HEREDOC_FILENAME_PREFIX "/tmp/heredoc_temp_"

int		has_quotes(const char *word);
void	delim_quote_remove(char **str);
int		link_input_file(const char *filename);
int		link_output_file(const char *filename, int append);
char	*expand_vars(const char *str, char **env);
char	*heredoc_filename(int n);
int		read_heredoc(const char *delim, int exp, const char *file, char **env);
int		link_heredoc(int n);

#endif
