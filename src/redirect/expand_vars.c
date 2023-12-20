/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:46:55 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/20 12:55:42 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include "env.h"

// Allocates and returns a copy of 'str' with its $VARIABLES expanded.
char	*expand_vars(const char *str, char **env)
{
	int		i;
	char	*ret_str;
	char	*tmp_str;
	char	*var;

	ret_str = ft_strdup("");
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '$' && str[++i] && (ft_isalpha(str[i]) || str[i] == '_'))
		{
			tmp_str = ft_substr(str, 0, i - 1);
			ft_strjoin_free(&ret_str, tmp_str);
			free(tmp_str);
			var = env_get_var(str + i, env);
			if (var)
				ft_strjoin_free(&ret_str, var);
			str += i + env_name_len(str + i);
			i = 0;
		}
		else
			i++;
	}
	ft_strjoin_free(&ret_str, str);
	return (ret_str);
}
