/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_remove_delimeter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:19:49 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/14 15:23:43 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc.h"

// Allocates and returns a string representing the given list of chars 'clst'.
static char	*clst_to_str(t_list *clst)
{
	char	*str;
	size_t	str_len;
	int		i;

	str_len = lst_size(clst);
	str = (char *)p_malloc(sizeof(char) * (str_len + 1));
	i = -1;
	while (clst && clst->val)
	{
		str[++i] = *(char *)(clst->val);
		clst = clst->nxt;
	}
	str[i + 1] = '\0';
	return (str);
}

// Performs quote removal on 'str'.
// Returns TRUE if any quote has been removed. Otherwise, returns FALSE.
int	quote_remove_delimeter(char **str)
{
	int		quote_removed;
	t_list	*char_lst;
	int		q_stat;
	int		char_stat;

	quote_removed = FALSE;
	q_stat = UNQUOTED;
	char_lst = NULL;
	while (**str)
	{
		char_stat = quote_stat(&q_stat, **str);
		if ((**str != '"' && **str != '\'') || char_stat != UNQUOTED)
			lst_add(&char_lst, lst_new(*str, sizeof(*str)));
		else
			quote_removed = TRUE;
		++str;
	}
	free(str);
	*str = clst_to_str(char_lst);
}
