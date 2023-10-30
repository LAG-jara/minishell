/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:49:48 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/30 15:01:41 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
# include "xtoken.h"

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

// Expands the env variables of the given token (if is word) and returns it 
// converted into a xtoken, with its appropiate xchar flags.
t_xtoken	*expand_tok(t_token	*tok, char **env)
{
	int		i;
	int		q_stat;
	char	*str;
	t_list	*xtok;

	q_stat = UNQUOTED;
	xtok = NULL;
	i = 0;
	while (tok && tok->val)
	{
		if (q_stat != QUOTED && tok->val[i] == '$' && valid_varname(tok[i + 1]))
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

// Given a list of tokens, allocates and returns a list of xtokens with its
// $VARIABLES expanded, preserving the original token type and setting each
// character's flags for expanded and quoted status.
t_list	*expand(t_list *toks, char **env)
{
	t_list		*xtoks;
	t_xtoken	xtok;
	t_list		*node;
	int			skip_next;

	skip_next = FALSE;
	xtoks = NULL;
	node = toks;
	while (node)
	{
		xtok = tok_to_xtok((t_token *)node->val);
		if (xtok.type == WORD)
		{
			if (skip_next)
				skip_next = FALSE;
			else
				expand_xtok(&xtok, env);
		}
		else if (!ft_strncmp(node->val, "<<", 3))
			skip_next = TRUE;
		lst_add(&xtoks, lst_new(&xtok, sizeof(t_xtoken)));
		node = node->nxt;
	}
	return (xtoks);
}


# include "debug.h"

int	main(void)
{
	char *pre_toks[] = \
	{ "ls", "arg1", "arg2", "|", "echo", "Holis", ":)", ">", "outfile", NULL};

	
}
