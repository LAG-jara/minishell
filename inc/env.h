/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:36:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/15 14:11:28 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdlib.h>
# include "arrstr.h"

char	**get_vars(const char *varname, char **env);
char	*get_var(const char *varname, char **env);
int		get_name_len(const char *str);
char	*find_var_line(const char *varname, char **env);
int		find_var_index(const char *varname, char **env);
void	set_env_var(const char *varname, const char *value, char ***env);
void	rm_env_var(const char *varname, char ***env);
int		valid_varname(const char *word);
char	*get_varname(const char *str);
void	env_free(char **env);

#endif
