/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:49:48 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/31 17:51:14 by glajara-         ###   ########.fr       */
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

// Returns TRUE if the list of xchars pointed by 'node' represents a string that
// should trigger an expansion.
// That is, a '$' followed by a '?' or an enviroment variable name.
static int	try_to_expand(t_list *node)
{
	int		ret;
	t_xchar	*xc;
	t_xchar	*xc_next;

	if (!node->nxt)
		return (FALSE);
	xc = (t_xchar *)node;
	xc_next = (t_xchar *)node->nxt;
	if (xc->q != QUOTED && xc->c == '$'
		&& (ft_isalpha(xc_next->c) || xc_next == '?'))
		return (TRUE);
	return (FALSE);
}

// Expands the env variables of the given xtoken (if is word), updating the
// expanded xchar flags if needed.
static void	expand_xtok(t_token	*xtok, char **env)
{
	t_list	*first_node;
	t_list	*curr_node;
	t_list	*expanded_val;

	if (xtok->type != WORD)
		return ;
	first_node = xtok->val;
	curr_node = xtok->val;
	while (curr_node && curr_node->val)
	{
		if (try_to_expand(curr_node))
		{
			if (((t_xchar *)((curr_node->nxt)->val))->c == '?')
				append_exp_errno(&first_node, curr_node);
			else
				append_exp_var(&first_node, curr_node, env);
		}
		// MAS
	}
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
