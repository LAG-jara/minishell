/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:09:27 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:45:27 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "get_input.h"
# include "tokenize.h"
# include "parse_tokens.h"
# include "expand_and_split.h"
# include "redirect_and_execute.h"
# include "signal_utils.h"

void	minish_loop(char **env);

#endif