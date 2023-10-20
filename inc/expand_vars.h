/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:41:56 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/20 12:48:20 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_VARS_H
# define EXPAND_VARS_H

# include "env.h"
# include "errno.h"
# include "gnl_utils.h"
# include "quote_utils.h"
# include "intarr_utils.h"

char	*expand_vars(char *str, int **expanded, char **env);

#endif