/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:16:17 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 17:47:40 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_PRIVATE_H
# define REDIRECT_PRIVATE_H

int		has_quotes(const char *word);
void	delim_quote_remove(char **str);
int		link_input_file(const char *filename);
int		link_output_file(const char *filename, int append);

#endif
