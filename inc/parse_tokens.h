/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:12:41 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/03 19:57:05 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TOKENS_H
# define PARSE_TOKENS_H

# include "errno.h"
# include "definitions.h"
# include "minish_consts.h"
# include "token_utils.h"
# include "basic_utils.h"
# include "arrstr.h"
# include "print_error.h"
# include "list.h"

t_list	**parse(char **tokens);

#endif
