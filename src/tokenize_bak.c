/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:44:44 by alajara-          #+#    #+#             */
/*   Updated: 2023/11/16 15:45:35 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

// Recives the input(in) and returns how many tokens there are. 
static int	count_tokens(const char *in)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (in[++i])
	{
		if (is_metachr(in[i]))
		{
			if (is_redirectionchr(in[i]) && is_redirectionchr(in[i + 1]))
				++i;
			if (is_operatorchr(in[i]))
				++count;
		}
		if (is_quotechr(in[i]))
			i += quote_skip(in, i);
		if (!is_metachr(in[i]) && (is_metachr(in[i + 1]) || !in[i + 1]))
			++count;
	}
	return (count);
}

// TOKEN
// A sequence of characters treated as a unit by the shell.
// Both operators and words are tokens.

// WORD
// A sequence of characters treated as a unit by the shell
// (excluding operators).
// Words may not include unquoted metacharacters.

// Returns the length of the next token of the input.
static int	toklen(const char *in, int i)
{
	int	len;

	len = 0;
	if (is_redirectionchr(in[i]) && in[i] == in[i + 1])
		return (2);
	if (is_operatorchr(in[i]))
		return (1);
	while (in[i + len] && !is_metachr(in[i + len]))
	{
		if (is_quotechr(in[i + len]))
			len += quote_skip(in, i + len);
		++len;
	}
	return (len);
}

// Recives the input(in) and fill the allocated spaces for the tokens.
static char	**fill_tokens(const char *in, char **tok)
{
	int	idx_in;
	int	len;
	int	idx_tok;

	idx_in = 0;
	idx_tok = -1;
	while (in[idx_in])
	{
		while (is_blankchr(in[idx_in]))
			++idx_in;
		len = toklen(in, idx_in);
		if (!len)
			break ;
		tok[++idx_tok] = (char *)p_malloc(sizeof(char) * len + 1);
		ft_strlcpy(tok[idx_tok], in + idx_in, len + 1);
		idx_in += len;
	}
	tok[++idx_tok] = NULL;
	return (tok);
}

// Splits the recived 'input' into an array of strings 
// NULL-terminated interpretable as tokens.
// And return it allocated.
char	**tokenize(const char *input)
{
	int		num_tokens;
	char	**tokens;

	num_tokens = count_tokens(input);
	tokens = (char **)p_malloc(sizeof(char *) * num_tokens + 1);
	tokens = fill_tokens(input, tokens);
	return (tokens);
}

// DELETE =-= DELETE =-= DELETE =-= DELETE =-= DELETE =-= DELETE =-=
/*
#include "debug.h"
int main()
{
	// char *s="fdgdf<Dfg$d a''a   a'a'a a'aaaaaa'aa ";
	// int n = toklen(s,6);
	// printf("%d", n);

	char	*s = "    $USER \t \" \" ' asd'asd  ";
	char	**tokens = tokenize(s);
	
	//printf("%s\n", tokens[0]);
	//printf("%s\n", tokens[1]);
	print_arrstr(tokens);

	return (0);
}*/