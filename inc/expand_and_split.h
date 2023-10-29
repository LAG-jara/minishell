/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:33:23 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/27 13:27:45 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_AND_SPLIT_H
# define EXPAND_AND_SPLIT_H

# include "definitions.h"
# include "env.h"
# include "expand_vars.h"
# include "normalize.h"
# include "remove_quotes.h"
# include "split_words.h"
# include "xlist.h"

char	***expand_and_split(char ***commands, char **env);

#endif