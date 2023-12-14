/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:16:17 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 17:32:11 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "list.h"

# define SAVE 1
# define RESTORE 0

int		redirect(t_list **cmd, char **env);
void	save_restore_stdio(int std_in, int std_out, int mode);

#endif
