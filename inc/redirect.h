/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:16:17 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 11:59:34 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "list.h"

# define SAVE 1
# define RESTORE 0

void	save_restore_stdio(int std_in, int std_out, int mode);
int		link_input_file(const char *filename);
int		link_output_file(const char *filename, int append);

int		redirect(t_list **cmd, char **env);

#endif
