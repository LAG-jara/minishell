/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:26:32 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 16:48:45 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "list.h"

enum e_token_type
{
	WORD,
	REDIR,
	PIPE,
	INVALID,
	NULL_TOK
};

// A token can be of type WORD, REDIRection, PIPE or INVALID.
// It's value is defined as a string.
typedef struct s_token
{
	char			*val;
	unsigned int	type : 3;
}	t_token;

void	tok_del(void *token);
int		tok_type(const char *str);
t_token	tok_create(const char *str);
t_token	*tok_get(t_list *node);
t_token	tok_create_null(void);

#endif