/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_exists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:11:41 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/21 20:46:27 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "boolean.h"

// Returns TRUE if the given 'path' exists. Otherwise, returns FALSE.
int	path_exists(const char *path)
{
	if (access(path, F_OK) == -1)
		return (FALSE);
	return (TRUE);
}
