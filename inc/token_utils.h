/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:26:32 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 17:33:39 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_UTILS_H
# define TOKEN_UTILS_H

# include "basic_utils.h"
# include "definitions.h"
# include "input_utils.h"
# include "quote_utils.h"
# include "list.h"

enum e_token_type {
	WORD,
	REDIR,
	PIPE,
	INVALID
};

// A token can be of type word, redirection, pipe or invalid.
// It's value is defined as a string.
typedef struct s_token
{
	char			*val;
	unsigned int	type : 2;
}	t_token;

void	tok_del(void *tok);
int		tok_type(const char *str);
t_token	tok_create(const char *str);
t_token	tok_get(t_list *node);

#endif