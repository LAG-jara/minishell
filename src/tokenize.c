/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:44:44 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/14 16:56:06 by alajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_metachar(int c)
{
	if(c == ' ' || c == '\t' || is_operator(c))
		return (1);
	return (0);
}

int	is_operator(int c)
{
	if(c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

int quote_skip(char *in, int i)
{
	char target;

	target = in[i++];
	while (in[i] != '\n' && in[i] != target)
		i++;
	return(i);
}

// A sequence of characters treated as a unit by the shell.
// Both operators and words are tokens.
// A sequence of characters treated as a unit by the shell (excluding operators).
// Words may not include unquoted metacharacters.
int	count_tokens(char *in)
{
	int	i;
	int count;

	count = 0;
	i = -1;
	while (in[++i] && in[i] != '\n')
	{
		while (is_metachar(in[i]))
		{
			if (in[i] == '>' || in[i] == '<' && in[i] == in[++i])
				i++;
			if (is_operator(in[i])
				count++;
			i++;
		}
		if (in[i] == '\'' || in[i] == '"')
			i = quote_skip(in, i);
		if (is_metachar(in[i + 1]))
			count++;
	}
	return (count);
}

// Splits the recived 'input' into a NULL-terminated array of tokens.
char	**tokenize(char *input)
{
	int		nb_tokens;
	char	**tokens;

	nb_tokens = count_tokens(input);
	tokens = (char **)malloc(sizeof(char *) * nb_tokens)
		if(!tokens)
			return (NULL);
	tokens = fill_tokens(input, tokens);
	return (tokens);
}
