/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:26:32 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/20 12:48:34 by glajara-         ###   ########.fr       */
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

int	token_type(char *token);

#endif