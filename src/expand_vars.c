/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:49:48 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/19 14:11:53 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_vars.h"

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
	free(var);
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

// Allocates and returns a copy of 'str' with its $VARIABLES expanded.
// 'expanded' has the ranges of the result that resulted from expansion.
char	*expand_vars(char *str, int **expanded, char **env)
{
	int		i;
	char	*ret_str;
	int		quote_status;

	ret_str = ft_strdup("");
	quote_status = UNQUOTED;
	i = 0;
	while (str && str[i])
	{
		quote_status = update_quote_status(quote_status, str[i]);
		if (quote_status != QUOTED && str[i] == '$'
			&& (str[i + 1] && (ft_isalpha(str[i + 1])) || str[i + 1] == '?'))
		{
			if (quote_status != DQUOTED)
				*expanded = intarr_add(*expanded, i + ft_strlen(ret_str));
			ret_str = append_exp(&str, &i, ret_str, env);
			if (quote_status != DQUOTED)
				*expanded = intarr_add(*expanded, i + ft_strlen(ret_str));
		}
		else
			i++;
	}
	ret_str = gnl_strjoin_free(ret_str, str);
	free(str);
	return (ret_str);
}

# include "debug.h"
int main(int ac, char **av, char **env)
{
	errno = 42;
	char	*token = ft_strdup2("hola $USER, como \"estas?  Errno: $?\"");
	int *expanded = intarr_dup(NULL);
	token = expand_vars(token, &expanded, env);
	printf("new token: %s\n\n", token);
	print_intarr(expanded);

	// int *expanded = intarr_dup(NULL);
	// expanded = intarr_add(expanded, 4);
	// expanded = intarr_add(expanded, 6);
	// expanded = intarr_add(expanded, 9);
	// expanded = intarr_add(expanded, 42);
	// print_intarr(expanded);
}