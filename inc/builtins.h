/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:16:57 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/04 19:09:08 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "list.h"

int	is_arg(char *unnedeed_arg);
int	is_validflag(char *flag);
int	exec_builtin(char **args, char ***env);

int	cd_builtin(char **word);
int	echo_builtin(char **word);
int	env_builtin(char **env);
int	exit_builtin();
int	export_builtin(char **word, char ***env);
int	pwd_builtin(void);
int	unset_builtin(char **word, char ***env);

int	is_builtin_name(char *str);		// TODO: definition on builtin_utils.c
int	is_builtin_cmd(t_list *cmd);

#endif
