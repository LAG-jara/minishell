/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:16:57 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/22 13:16:59 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_UTILS_H
# define BASIC_UTILS_H

void	cd_builtin(char **comm, char **env);
void	echo_builtin(char **comm);
void	env_builtin(char **env);
void	exit_builtin(char **comm);
void	export_builtin(char **comm, char **env);
void	pwd_builtin(char **env);
void	unset_builtin(char **comm, char **env);

#endif