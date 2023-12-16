/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_heredocs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:03:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/16 17:56:58 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_private.h"
#include <stdlib.h>
#include <unistd.h>

// Removes the temporary here document files, up to the 'n'-th command.
void	clear_heredocs(int n)
{
	char	*filename;

	while (n-- >= 0)
	{
		filename = heredoc_filename(n);
		unlink(filename);
		free(filename);
	}
}
