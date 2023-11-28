/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:33:23 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/28 18:19:48 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_AND_SPLIT_H
# define EXPAND_AND_SPLIT_H

# include "definitions.h"
# include "env.h"
# include "quote_utils.h"
# include "xtoken.h"
# include "list.h"

t_list	**expand_and_split(t_list **commands, int exit_status, char **env);

t_list	*expand(t_list *toks, int exit_status, char **env);
void	split_words(t_list **xtokens);
void	remove_quotes(t_list *xtokens);
t_list	*normalize(t_list *xtokens);

#endif