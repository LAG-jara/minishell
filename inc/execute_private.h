/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:20:23 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:56:34 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_PRIVATE_H
# define EXECUTE_PRIVATE_H

# include "list.h"

char	**get_args_from_cmd(t_list *cmd);
void	exec_cmd(char **cmd, char **env);

#endif
