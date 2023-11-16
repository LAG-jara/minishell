/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:35:46 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/16 16:22:28 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include "basic_utils.h"
# include "input_utils.h"
// # include "quote_utils.h"
# include "token_utils.h"

t_list	*tokenize(const char *input);

#endif