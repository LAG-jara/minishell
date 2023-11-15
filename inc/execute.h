/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:20:23 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/15 15:41:16 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "list.h"

void	exec_cmd(char **cmd, char **env);
int		execute_builtin(t_list *cmd, char ***env);
void	execute_command(t_list *cmd, char **env);

#endif
