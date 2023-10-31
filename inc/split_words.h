/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:38:44 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 17:34:24 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_WORDS_H
# define SPLIT_WORDS_H

# include "basic_utils.h"
# include "definitions.h"
# include "input_utils.h"
# include "is_expanded.h"
# include "arrstr_utils.h"
# include "quote_utils.h"
# include "xtoken.h"

void	split_words(t_list *xtokens);

#endif
