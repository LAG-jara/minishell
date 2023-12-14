/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split_private.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:33:23 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 16:16:38 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_AND_SPLIT_PRIVATE_H
# define EXPAND_AND_SPLIT_PRIVATE_H

# include "list.h"

t_list	*expand(t_list *toks, int exit_status, char **env);
void	split_words(t_list **xtokens);
void	remove_quotes(t_list *xtokens);
t_list	*normalize(t_list *xtokens);

#endif