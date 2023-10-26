/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrint_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:47:42 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 12:27:19 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRINT_UTILS_H
# define ARRINT_UTILS_H

# include <stdlib.h>
# include "basic_utils.h"

int		arrint_size(int *arr);
int		*arrint_dup(int *arr);
int		*arrint_add(int *arr, int n);

#endif