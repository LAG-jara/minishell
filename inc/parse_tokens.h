/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:12:41 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 19:14:54 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_TOKENS_H
# define PARSE_TOKENS_H

# include "list.h"

t_list	**parse(t_list *tokens, int *exit_status);

#endif
