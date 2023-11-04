/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:19:28 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 18:01:03 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAIT_CHILDREN_H
# define WAIT_CHILDREN_H

# include <sys/wait.h>
# include <stdlib.h>

int	wait_children(pid_t last_child_pid);

#endif