/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:49:48 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/29 12:57:38 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
# include "xchar.h"

// Given that *str[*i] points to the $ character of an environment variable,
// expands its value and appends it to 'prev_str' and 'str' (until 'i').
// The appended result is returned and the 'str' pointer moved forward.
static char	*append_exp_var(char **str, int *i, char *prev_str, char **env)
{
	char	*tmp_str;
	char	*var;

	tmp_str = gnl_substr(*str, 0, *i);
	prev_str = gnl_strjoin_free(prev_str, tmp_str);
	free(tmp_str);
	var = get_var(&(*str)[*i], env);
	if (var)
		prev_str = gnl_strjoin_free(prev_str, var);
	*str += *i + get_name_len(&(*str)[*i]);
	*i = 0;
	return (prev_str);
}

// Given that *str[*i] points to the $ character of "$?", expands the value 
// of errno and appends it to 'prev_str' and 'str' (until 'i').
// The appended result is returned and the 'str' pointer moved forward.
static char	*append_exp_errno(char **str, int *i, char *prev_str)
{
	char	*tmp_str;
	char	*var;

	tmp_str = gnl_substr(*str, 0, *i);
	prev_str = gnl_strjoin_free(prev_str, tmp_str);
	free(tmp_str);
	var = ft_itoa(errno);
	if (var)
		prev_str = gnl_strjoin_free(prev_str, var);
	// free(var);
	*str += *i + 2;
	*i = 0;
	return (prev_str);
}

// Given that *str[*i] points to the $ character of "$?" or an env variable,
// expands the value and appends it to 'prev_str' and 'str' (until 'i').
// The appended result is returned and the 'str' pointer moved forward.
static char	*append_exp(char **str, int *i, char *prev_str, char **env)
{
	if ((*str)[*i + 1] == '?')
		return (append_exp_errno(str, i, prev_str));
	else
		return (append_exp_var(str, i, prev_str, env));
}

t_lst	*expand_tok(char *tok, char **env)
{
	int		i;
	int		q_stat;
	char	*str;
	t_lst	*xtok;

	q_stat = UNQUOTED;
	xtok = NULL;
	i = 0;
	while (tok && tok[i])
	{
		q_stat = quote_stat(q_stat, tok[i]);
		if (q_stat != QUOTED && tok[i] == '$' && valid_varname(tok[i + 1]))
		{
			str = expand_var(tok[i]);
			xtok = xtok_adds(*xtok, str);
			i += ft_strlen(str);
		}
		else
		{
			xtok_addc(*xtok, tok[i])
			++i;
		}
	}
	return
}

// Given an array of tokens, allocates and returns a list of tokens with its
// $VARIABLES expanded. Each listed token is represented as a t_lst of t_xchars.
t_lst	*expand(char **toks, char **env)
{
	int		i;
	t_lst	*xtok;
	t_lst	*xtoks;

	xtoks = NULL;
	i = -1;
	while (toks && toks[++i])
	{
		xtok = expand_tok(toks[i], env);
		lst_add(*xtoks, lst_new(xtok));
	}
	return (xtoks);
}
