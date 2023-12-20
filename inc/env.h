/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:36:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/20 12:55:42 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

char	**env_get_vars(const char *varname, char **env);
char	*env_get_var(const char *varname, char **env);
int		env_name_len(const char *str);
void	env_set_var(const char *varname, const char *value, char ***env);
void	env_rm_var(const char *varname, char ***env);
int		env_valid_varname(const char *word);
char	*env_get_varname(const char *str);

#endif
