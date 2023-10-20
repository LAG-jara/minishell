/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:14:14 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/20 18:41:22 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_words.h"

// Returns TRUE or FALSE whether 'index' is in one of the 'expanded' ranges.
// 'expanded' includes indexes in ascending order so even indexes defines a
// range start (inclusive) and odd indexes defines ends (exclusive).
static int	is_expanded(int index, int *expanded)
{
	int	i;

	if (!expanded)
		return (FALSE);
	i = -1;
	while (expanded[++i] != -1)
	{
		if (index < expanded[i])
			return (FALSE);
		if (index == expanded[i])
			return (TRUE);
		if (index > expanded[i] && index < expanded[i + 1])
			return (TRUE);
		++i;
	}
	return (FALSE);
}

// Returns TRUE if 'c' is to be considered a delimiter, given its 'index' and
// the 'expanded' ranges (read comment of the 'is_expanded' function).
static int	is_delim(char c, int index, int *expanded, int quote_status)
{
	if (is_expanded(index, expanded) && is_blankchr(c)
		&& quote_status != DQUOTED)
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
	int	quote_status;
	int	i;

	count = 0;
	is_word = FALSE;
	quote_status = UNQUOTED;
	i = -1;
	while (token[++i])
	{
		quote_status = update_quote_status(quote_status, token[i]);
		if (is_delim(token[i], i, expanded, quote_status))
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
	int		quote_status;

	quote_status = UNQUOTED;
	--(*i);
	while (token[++(*i)])
	{
		quote_status = update_quote_status(quote_status, token[*i]);
		if (!is_delim(token[*i], *i, expanded, quote_status))
			break ;
	}
	w_len = -1;
	while (token[*i + ++(w_len)])
	{
		quote_status = update_quote_status(quote_status, token[*i + w_len]);
		if (is_delim(token[*i + w_len], (*i + w_len), expanded, quote_status))
			break ;
	}
	word = (char *) p_malloc((w_len + 1) * sizeof(char));
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
	int		indx;
	int		i;

	words_amount = count_words_amount(token, expanded);
	split_tok = (char **) p_malloc(sizeof(char *) * (words_amount + 1));
	indx = 0;
	i = -1;
	while (++i < words_amount)
		split_tok[i] = pop_word(token, &indx, expanded);
	split_tok[i] = NULL;
	return (split_tok);
}

// #include "debug.h"
// #include "intarr_utils.h"
// int main(int ac, char **av, char **env)
// {
// 	char	*token = ft_strdup2("   uno    dos tres    .");
// 	int		*expanded = intarr_dup(NULL);
// 	expanded = intarr_add(expanded, 2);
// 	expanded = intarr_add(expanded, 11);
// 	expanded = intarr_add(expanded, 12);
// 	expanded = intarr_add(expanded, 14);

// 	char	**split_tok = split_words(token, expanded);

// 	printf("SPLIT TOKEN:\n");
// 	print_strarr(split_tok);
// }