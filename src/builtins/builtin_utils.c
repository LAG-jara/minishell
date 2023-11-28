/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:04:19 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/28 19:43:24 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"
#include "token_utils.h"

// Returns TRUE if the string 'str' is the name of a builtin.
int	is_builtin_name(char *str)
{
	if (!ft_strncmp(str, "cd", 3) || !ft_strncmp(str, "echo", 5) || \
	!ft_strncmp(str, "env", 4) || !ft_strncmp(str, "exit", 5) || \
	!ft_strncmp(str, "export", 7) || !ft_strncmp(str, "pwd", 4) || \
	!ft_strncmp(str, "unset", 6))
		return (TRUE);
	return (FALSE);
}

// Returns TRUE if the list 'cmd' is suposed to execute a builtin.
int	is_builtin_cmd(t_list *cmd)
{
	t_list	*node;
	t_token	*tok;

	node = cmd;
	if (node)
	{
		tok = tok_get(node);
		while (tok->type == REDIR)
		{
			node = lst_move(node, 2);
			if (!node)
				return (FALSE);
			tok = tok_get(node);
		}
		if (is_builtin_name(tok->val))
			return (TRUE);
	}
	return (FALSE);
}

// // Checks for more arguments in builtins that don't use it.
// int		is_arg(char *unnedeed_arg)
// {

// }

// // Check for flags in the builtins that need them and use it in the builtin.
// int		is_validflag(char *flag)
// {

// }