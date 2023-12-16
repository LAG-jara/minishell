/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:16:17 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/16 17:51:39 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "list.h"

# define SAVE 1			// Save mode for save_restore_stdio()
# define RESTORE 0		// Restore mode for save_restore_stdio()

int		redirect(t_list **cmd, int n);
void	save_restore_stdio(int std_in, int std_out, int mode);
int		read_heredocs(t_list *cmd, int n, char **env);
void	clear_heredocs(int n);

#endif
