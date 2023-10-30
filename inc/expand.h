/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:41:56 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/30 11:36:28 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "env.h"
# include "errno.h"
# include "gnl_utils.h"
# include "quote_utils.h"
# include "xlist.h"

t_list	*expand(char *str, char **env);

#endif