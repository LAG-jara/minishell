/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_and_execute.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:36:12 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/22 12:37:22 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_AND_EXECUTE_H
# define REDIRECT_AND_EXECUTE_H

# include "basic_utils.h"
# include "builtins.h"
# include "execute.h"
# include "pipe.h"
# include "redirect.h"
# include <unistd.h>

void	redirect_and_execute(t_list **commands, int *exit_status, char ***env);

#endif
