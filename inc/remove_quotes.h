/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:44:57 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 12:16:36 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REMOVE_QUOTES_H
# define REMOVE_QUOTES_H

# include "quote_utils.h"
# include "arrint_utils.h"
# include "definitions.h"
# include "basic_utils.h"

char	**remove_quotes(char **tokens, int *expanded);

#endif