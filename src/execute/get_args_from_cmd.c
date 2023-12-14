/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_from_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:21:54 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/14 18:11:38 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include "token.h"
#include "list.h"

// Allocates and returns a NULL-terminated array of strings representing the
// list of tokens 'cmd'.
char	**get_args_from_cmd(t_list *cmd)
{
	char	**args;
	size_t	len;
	t_token	*tok;
	int		i;

	len = lst_size(cmd);
	args = (char **)p_malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (cmd)
	{
		tok = tok_get(cmd);
		args[i++] = ft_strdup(tok->val);
		cmd = cmd->nxt;
	}
	args[i] = NULL;
	return (args);
}
