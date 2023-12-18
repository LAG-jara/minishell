/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all_heredocs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:39:08 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/18 17:47:58 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_and_execute_private.h"
#include "redirect.h"
#include "signal_utils.h"

// Reads all the here documents from the array of commands 'cmds', from left
// to right, into the appropriate temp files to be read afterwards.
// Returns 0 on success. Otherwise, returns a non-zero value.
int	read_all_heredocs(t_list **cmds, int cmds_amount, char **env)
{
	int		i;
	int		ret;

	stop_signals();
	i = -1;
	while (++i < cmds_amount)
	{
		ret = read_heredocs(cmds[i], i, env);
		if (ret)
			return (ret);
	}
	return (0);
}
