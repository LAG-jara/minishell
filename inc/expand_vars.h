/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:41:56 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/18 19:31:18 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_VARS_H
# define EXPAND_VARS_H

# include "gnl_utils.h"
# include "token_utils.h"
# include "env.h"
# include "errno.h"

char	*expand_vars(char *str, char **env);

#endif