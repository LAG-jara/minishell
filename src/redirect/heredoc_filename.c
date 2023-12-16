/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_filename.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:01:27 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/16 17:04:40 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_private.h"
#include "basic_utils.h"

// Allocates and returns a string representing the here document temp filename
// for the 'n'-th command.
char	*heredoc_filename(int n)
{
	char	*tmp;
	char	*filename;

	filename = ft_strdup(HEREDOC_FILENAME);
	tmp = ft_itoa(n);
	ft_strjoin_free(&filename, tmp);
	free(tmp);
	return (filename);
}
