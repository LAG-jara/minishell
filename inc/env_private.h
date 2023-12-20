/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:36:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/20 12:48:26 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_PRIVATE_H
# define ENV_PRIVATE_H

int		env_find_var_index(const char *varname, char **env);
char	*env_find_var_line(const char *varname, char **env);

#endif
