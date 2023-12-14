/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:03:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 17:04:35 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_private.h"
#include <unistd.h>

// Removes the temporary here document file.
void	clear_heredoc(void)
{
	unlink(HEREDOC_FILENAME);
}
