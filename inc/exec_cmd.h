/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:39:36 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/14 12:17:27 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_CMD_H
# define EXEC_CMD_H

# include "basic_utils.h"
# include "env.h"			// using: get_paths
# include <errno.h>			// using: errno
# include "minish_consts.h"	// using: SH_NAME
# include <string.h>		// using: strerror()
# include <unistd.h>		

# define CMD_NOT_FOUND		127	// Error code for "Command not found"
# define CMD_PERM_DENIED	126	// Error code for "Permission denied"

char	**get_args_from_cmd(t_list *cmd);
void	exec_cmd(char **cmd, char **env);

#endif
