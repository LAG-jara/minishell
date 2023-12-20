/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:16:57 by alajara-          #+#    #+#             */
/*   Updated: 2023/12/20 17:21:16 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_PRIVATE_H
# define BUILTINS_PRIVATE_H

# define LLINT_MIN_STR "9223372036854775808"
# define LLINT_MAX_STR "9223372036854775807"

int	cd_builtin(char **args, char **env);
int	echo_builtin(char **args);
int	env_builtin(char **env);
int	exit_builtin(char **args, int exit_status, int is_child);
int	export_builtin(char **args, char ***env);
int	pwd_builtin(void);
int	unset_builtin(char **args, char ***env);

#endif
