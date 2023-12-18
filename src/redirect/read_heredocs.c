/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_heredocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:03:25 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/18 17:39:14 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_private.h"
#include "token.h"
#include "quote_utils.h"
#include "basic_utils.h"

// Reads the here document for the 'n'-th command, assuming 'str' is the word
// right next to the << token.
// Returns 0 on success, or -1 in case of failure (setting errno).
static int	read_heredoc_n(const char *str, int n, char **env)
{
	char	*delim;
	int		expand;
	char	*file;
	int		ret;

	delim = ft_strdup(str);
	expand = !has_quotes(delim);
	delim_quote_remove(&delim);
	file = heredoc_filename(n);
	ret = read_heredoc(delim, expand, file, env);
	free(delim);
	free(file);
	return (ret);
}

// Reads the here documents for 'cmd' from left to right, into a temp file
// knowing it's the 'n'-th command.
// If there's more than one here document, the previous ones are overwritten.
// Returns 0 on success. Otherwise, returns a non-zero value.
int	read_heredocs(t_list *cmd, int n, char **env)
{
	t_list	*node;
	t_token	*tok;
	int		err;

	node = cmd;
	while (node)
	{
		tok = tok_get(node);
		if (tok->type == REDIR && !ft_strncmp(tok->val, "<<", 3))
		{
			err = read_heredoc_n(tok_get(node->nxt)->val, n, env);
			if (err)
				return (err);
			node = node->nxt;
		}
		node = node->nxt;
	}
	return (EXIT_SUCCESS);
}
