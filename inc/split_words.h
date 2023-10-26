/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:38:44 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 12:11:23 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_WORDS_H
# define SPLIT_WORDS_H

# include "basic_utils.h"
# include "definitions.h"
# include "input_utils.h"
# include "arrstr_utils.h"
# include "quote_utils.h"

char	**split_words(char *token, int *expanded);

#endif
