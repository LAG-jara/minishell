/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:36:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/03 19:57:05 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdlib.h>
# include "arrstr.h"

char	**get_paths(char **env);
char	*get_var(char *varname, char **env);
int		get_name_len(char *str);
char	*find_var_line(char *varname, char **env);
int		find_var_index(char *varname, char **env);
void	set_env_var(char *varname, char *value, char ***env);
void	rm_env_var(char *varname, char ***env);
int		valid_varname(char *word);
char	*get_varname(char *str);
void	env_free(char **env);

#endif
