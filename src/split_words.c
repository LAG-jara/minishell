/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:14:14 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/26 18:03:45 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_words.h"

// Returns TRUE if 'c' is to be considered a delimiter, given its 'index' and
// the 'expanded' ranges (read comment of the 'is_expanded' function).
static int	is_delim(char c, int index, int *expanded, int q_stat)
{
	if (is_expanded(index, expanded) && is_blankchr(c)
		&& q_stat != DQUOTED)
		return (TRUE);
	else
		return (FALSE);
}

// Counts the amount of words resulting from splitting 'token' using <space>
// and <tab> as a delimiter, only in the ranges defined by 'expanded'.
// expanded[i] where i is even: start (inclusive), i odd: end (exclusive).
static int	count_words_amount(char *token, int *expanded)
{
	int	count;
	int	is_word;
	int	q_stat;
	int	i;

	count = 0;
	is_word = FALSE;
	q_stat = UNQUOTED;
	i = -1;
	while (token[++i])
	{
		q_stat = quote_stat_exp(q_stat, token[i], expanded, i);
		if (is_delim(token[i], i, expanded, q_stat))
			is_word = FALSE;
		else if (!is_word)
		{
			is_word = TRUE;
			count++;
		}
	}
	return (count);
}

// Allocates and returns the first word on 'token' (starting at 'i') using 
// <space> and <tab> as delimiters, only in the ranges defined by 'expanded'.
// The token's index 'i' is now pointing just after the popped word.
static char	*pop_word(char *token, int *i, int *expanded)
{
	char	*word;
	size_t	w_len;
	int		q_stat;

	q_stat = UNQUOTED;
	--(*i);
	while (token[++(*i)])
	{
		q_stat = quote_stat_exp(q_stat, token[*i], expanded, *i);
		if (!is_delim(token[*i], *i, expanded, q_stat))
			break ;
	}
	w_len = -1;
	while (token[*i + ++(w_len)])
	{
		q_stat = quote_stat_exp(q_stat, token[*i + w_len], expanded,\
		*i + w_len);
		if (is_delim(token[*i + w_len], (*i + w_len), expanded, q_stat))
			break ;
	}
	word = (char *)p_malloc((w_len + 1) * sizeof(char));
	ft_strlcpy(word, &token[*i], w_len + 1);
	*i += w_len;
	return (word);
}

// Given that 'expanded' defines the ranges [even: start(incl), odd: end(excl)]
// that resulted from expansion, performs word-splitting acording to the manual.
// TODO : add link
char	**split_words(char *token, int *expanded)
{
	int		words_amount;
	char	**split_tok;
	int		idx;
	int		i;

	words_amount = count_words_amount(token, expanded);
	split_tok = (char **)p_malloc(sizeof(char *) * (words_amount + 1));
	idx = 0;
	i = -1;
	while (++i < words_amount)
		split_tok[i] = pop_word(token, &idx, expanded);
	split_tok[i] = NULL;
	return (split_tok);
}

// #include "debug.h"
// #include "arrint_utils.h"
// int main(int ac, char **av, char **env)
// {
// 	char	*token = ft_strdup("   uno    dos tres    .");
// 	int		*expanded = arrint_dup(NULL);
// 	expanded = arrint_add(expanded, 2);
// 	expanded = arrint_add(expanded, 11);
// 	expanded = arrint_add(expanded, 12);
// 	expanded = arrint_add(expanded, 14);

// 	char	**split_tok = split_words(token, expanded);

// 	printf("SPLIT TOKEN:\n");
// 	print_arrstr(split_tok);
// }