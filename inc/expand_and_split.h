/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:33:23 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/03 12:13:45 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_AND_SPLIT_H
# define EXPAND_AND_SPLIT_H

# include "definitions.h"
# include "env.h"
# include "errno.h"
# include "quote_utils.h"
# include "xtoken.h"
# include "list.h"

t_list	**expand_and_split(t_list **commands, char **env);

t_list	*expand(t_list *toks, char **env);
void	split_words(t_list **xtokens);
void	remove_quotes(t_list **xtoken);
t_list	*normalize(t_list **xtokens);


#endif