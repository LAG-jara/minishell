/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:26:32 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/19 09:50:42 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_UTILS_H
# define TOKEN_UTILS_H

# include "basic_utils.h"
# include "definitions.h"

# define UNQUOTED 0
# define QUOTED 1
# define DQUOTED 2

enum e_token_type {
	WORD,
	REDIR_OP,
	CTRL_OP,
	INVALID
};

int	is_word(char *str);
int	quote_skip(char *in, int i);
int	token_type(char *token);
int	update_quote_status(int curr_status, char c);
int	update_quote_status_2(int curr_status, char c, int *flag);

#endif