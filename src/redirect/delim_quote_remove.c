/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delim_quote_remove.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:19:49 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/14 15:23:43 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_utils.h"
#include "input_utils.h"

// Performs quote removal on 'word'.
void	delim_quote_remove(char **word)
{
	char	last_quote;
	int		i;
	int		j;
	char	*str;

	str = (char *)p_malloc(sizeof(char) * (ft_strlen(word[0]) + 1));
	i = -1;
	j = -1;
	last_quote = 0;
	while (word[0][++i])
	{
		if (last_quote != 0 && last_quote == word[0][i])
			last_quote = 0;
		else if (last_quote == 0 && is_quotechr(word[0][i]))
			last_quote = word[0][i];
		else
			str[++j] = word[0][i];
	}
	str[++j] = '\0';
	*word = str;
}
