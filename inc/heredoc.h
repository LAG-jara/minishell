/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:19:43 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 20:03:17 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

int		read_heredoc(const char *delimiter, int expand, char **env);
int		link_heredoc(void);
void	clear_heredoc(void);

#endif
