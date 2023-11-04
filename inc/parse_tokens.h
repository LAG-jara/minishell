/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:12:41 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 13:53:56 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TOKENS_H
# define PARSE_TOKENS_H

# include "definitions.h"
# include "token_utils.h"
# include "arrstr.h"
# include "print_error.h"
# include "list.h"

t_list	**parse(char **tokens, int *exit_status);

#endif
