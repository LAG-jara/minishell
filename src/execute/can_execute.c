/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:12:34 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/21 20:46:04 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "boolean.h"

// Returns TRUE if 'path' is an executable file. Otherwise, returns FALSE.
int	can_execute(const char *path)
{
	if (access(path, X_OK) == -1)
		return (FALSE);
	return (TRUE);
}
