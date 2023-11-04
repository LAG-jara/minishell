/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:04:19 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 19:08:46 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"
#include "token_utils.h"

// Returns TRUE if the string 'str' is the name of a builtin.
int	is_builtin_name(char *str)
{
	// TODO
	return (FALSE);
}

// Returns TRUE if the list 'cmd' is suposed to execute a builtin.
int	is_builtin_cmd(t_list *cmd)
{
	t_list	*node;
	t_token	tok;

	node = cmd;
	while (node)
	{
		tok = tok_get(node);
		if (tok.type == REDIR)
			node = lst_move(node, 2);
		else if (is_builtin_name(tok.val))
			return (TRUE);
		return (FALSE);
	}
	return (FALSE);
}
