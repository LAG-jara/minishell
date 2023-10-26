/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:25:02 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 17:31:40 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "remove_quotes.h"
# include "debug.h"

// Returns TRUE if 'c' is an unquoted quote that didn't result from expansion.
static int	is_quote_to_rm(char c, int quote_stat, int i, int *expanded)
{
	if ((c == '"' || c == '\'')
		&& quote_stat == UNQUOTED
		&& !is_expanded(i, expanded))
		return (TRUE);
	else
		return (FALSE);
}

// Removes all unquoted ocurrences of ' and " that didn't result form expansion,
// taking (and updating) the given 'quote_stat' and 'i' into account.
static char	*rm_quotes_tok(char *token, int *quote_stat, int *i, int *expanded)
{
	char	*new_token;
	int		index;
	int		*to_delete;

	to_delete = arrint_dup(NULL);
	index = -1;
	while (token[++index])
	{
		++(*i);
		*quote_stat = upd_quote_stat(*quote_stat, token[index]);
		if (is_quote_to_rm(token[index], *quote_stat, *i, expanded))
			to_delete = arrint_add(to_delete, *i);
	}
	// printf("TO DELETE:\n");
	// print_arrint(to_delete);
	new_token = rm_at_indexes(token, to_delete);
	free(token);
	return (new_token);
}

// Removes all unquoted ocurrences of ' and " that didn't result form expansion.
// The 'tokens' are expanded and word-splitted, and 'expanded' defines the
// ranges [even: start(incl), odd: end(excl)] that resulted from expansion.
char	**remove_quotes(char **tokens, int *expanded)
{
	int		quote_stat;
	int		i;
	int		j;

	quote_stat = UNQUOTED;
	i = 0;
	j = -1;
	while (tokens[++j])
		tokens[j] = rm_quotes_tok(tokens[j], &quote_stat, &i, expanded);
	return (tokens);
}
