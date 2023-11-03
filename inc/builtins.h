/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:16:57 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/25 14:33:10 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

void	cd_builtin(char **word, char ***env);
void	echo_builtin(char **word);
void	env_builtin();
void	exit_builtin();
void	export_builtin(t_list *word, char ***env);
void	pwd_builtin();
void	unset_builtin(char **word, char ***env);

#endif