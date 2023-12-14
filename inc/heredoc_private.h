/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:19:43 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 20:02:59 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_PRIVATE_H
# define HEREDOC_PRIVATE_H

# define HEREDOC_FILENAME "/tmp/heredoc_temp"

char	*expand_vars(const char *str, char **env);

#endif
