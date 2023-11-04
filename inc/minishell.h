/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:09:27 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 14:28:30 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "get_input.h"
# include "tokenize.h"
# include "parse_tokens.h"
# include "expand_and_split.h"

void	minish_loop(char **env);

#endif