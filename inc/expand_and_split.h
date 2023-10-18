/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:33:23 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/18 17:04:37 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_AND_SPLIT_H
# define EXPAND_AND_SPLIT_H

# include "env.h"
# include "definitions.h"

char	***expand_and_split(char ***commands, char **env);

#endif