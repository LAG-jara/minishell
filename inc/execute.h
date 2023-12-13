/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:20:23 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/23 15:32:04 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "list.h"

void	exec_cmd(char **cmd, char **env);
int		execute_builtin(t_list *cmd, int exit_status, char ***env, int is_child);
void	execute_command(t_list *cmd, int exit_status, char **env);

#endif
