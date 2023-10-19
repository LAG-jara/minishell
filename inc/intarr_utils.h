/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intarr_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:47:42 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/19 11:39:33 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTARR_UTILS_H
# define INTARR_UTILS_H

# include <stdlib.h>
# include "basic_utils.h"

size_t	intarr_get_size(int *arr);
int		*intarr_dup(int *arr);
int		*intarr_add(int *arr, int n);

#endif