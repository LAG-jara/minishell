/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:49:48 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/18 19:43:02 by glajara-         ###   ########.fr       */
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

// Allocates and returns a copy of 'str' with its $VARIABLES expanded.
char	*expand_vars(char *str, char **env)
{
	int		i;
	char	*ret_str;
	int		quote_status;

	quote_status = UNQUOTED;
	ret_str = ft_strdup("");
	i = 0;
	while (str && str[i])
	{
		quote_status = update_quote_status(quote_status, str[i]);
		if (quote_status != QUOTED && str[i] == '$' && str[i + 1]
			&& ft_isalpha(str[i + 1]) == TRUE)
			ret_str = append_exp_var(&str, &i, ret_str, env);
		else if (quote_status != QUOTED && str[i] == '$' && str[i + 1] == '?')
			ret_str = append_exp_errno(&str, &i, ret_str);
		else
			i++;
	}
	ret_str = gnl_strjoin_free(ret_str, str);
	return (ret_str);
}

# include <stdio.h>
int main(int ac, char **av, char **env)
{
	errno = 42;
	char	*token = ft_strdup2("\"hola $USER, como estas?\nErrno: $?\"");
	token = expand_vars(token, env);
	printf("new token: %s\n", token);
}