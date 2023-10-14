/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:55:53 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/14 16:03:24 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av, char **env)
{
	char	*input;
	char	**tokens;
	char	***commands;

	while (42)
	{
		input = get_input(env);
		tokens = tokenize(input);
		commands = parse(tokens, &env);
		if (!commands)
			continue;
		commands = expand(commands, env);
		commands = remove_quotes(commands);
		redirect_and_execute(commands, &env);
	}
	return (0);
}
