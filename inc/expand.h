/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:41:56 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/01 09:44:29 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "env.h"
# include "errno.h"
# include "gnl_utils.h"
# include "quote_utils.h"
# include "xtoken.h"

t_list	*expand(t_list *toks, char **env);

#endif