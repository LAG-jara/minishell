/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:26:32 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/29 19:28:02 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_UTILS_H
# define TOKEN_UTILS_H

# include "basic_utils.h"
# include "definitions.h"
# include "input_utils.h"
# include "quote_utils.h"

enum e_token_type {
	WORD,
	REDIR_OP,
	CTRL_OP,
	INVALID
};

typedef struct s_token
{
	char			*val;
	unsigned int	type : 2;
}	t_token;

int		token_type(char *token);
t_token	token_create(char *str);

#endif