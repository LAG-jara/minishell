/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_and_split.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:33:23 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 16:01:02 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_AND_SPLIT_H
# define EXPAND_AND_SPLIT_H

# include "list.h"

t_list	**expand_and_split(t_list **commands, int exit_status, char **env);

#endif