/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:14:14 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/19 15:52:55 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_words.h"

// Returns TRUE if 'c' is to be considered a delimiter, given its 'index' and
// the 'expanded' ranges (read comment of the 'is_expanded' function).
static int	is_delim(char c, int index, int *expanded)
{
	if (is_expanded(index, expanded) && is_blankchr(c))
		return (TRUE);
	else
		return (FALSE);
}

// Returns TRUE or FALSE whether 'index' is in one of the 'expanded' ranges.
// 'expanded' includes indexes in ascending order so even indexes defines a
// range start (inclusive) and odd indexes defines ends (exclusive).
static int	is_expanded(int index, int *expanded)
{
	int	is_exp;
	int	i;

	if (!expanded)
		return (FALSE);
	is_exp = FALSE;
	i = -1;
	while (expanded[++i] != -1)
	{
		if (index < expanded[i])
			return (FALSE);
		if (index >= expanded[i] && index < expanded[i + 1])
			return (TRUE);
		++i;
	}
	return (FALSE);
}

// Counts the amount of words resulting from splitting 'token' using <space>
// and <tab> as a delimiter, only in the ranges defined by 'expanded'.
// expanded[i] where i is even: start (inclusive), i odd: end (exclusive).
static int	count_words_amount(char *token, int *expanded)
{
	int	count;
	int	is_word;
	int i;

	is_word = FALSE;
	count = 0;
	i = -1;
	while (token[++i])
	{
		if (is_delim(token[i], i, expanded))
			is_word = FALSE;
		else
		{
			if (!is_word)
			{
				is_word = TRUE;
				count++;
			}
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
	char	*tok;
	size_t	word_len;

	word_len = 0;
	while (token[*i] && is_delim(token[*i], *i, expanded))
		(*i)++;
	while (token[*i + word_len] && !is_delim(token[*i + word_len], i, expanded))
		word_len++;
	word = (char *) p_malloc((word_len + 1) * sizeof(char));
	ft_strlcpy(word, token[*i], word_len + 1);
	*i += word_len;
	return (word);
}

// Given that 'expanded' defines the ranges [even: start(incl), odd: end(excl)]
// in which a value was expanded (excluding those that were double-quoted),
// performs word-splitting acording to the manual. // TODO : add link
char	**split_words(char *token, int *expanded)
{
	int		words_amount;
	char	**split_tok;
	int		i;

	words_amount = count_words_amount(token, expanded);
	split_tok = (char **) p_malloc(sizeof(char *) * (words_amount + 1));
	i = -1;
	while (++i < words_amount)
		split_tok[i] = pop_word(token, &i, expanded);
	split_tok[i] = NULL;
	return (split_tok);
}
