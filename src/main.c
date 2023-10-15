/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:55:53 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/15 14:32:29 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av, char **environ)
{
	char	**env;
	char	*input;
	char	**tokens;
	char	***commands;

	env = dup_strarr2(environ);
	while (42)
	{
		input = get_input(env);
		tokens = tokenize(input);
		commands = parse(tokens, &env);
		if (!commands)
			continue ;
		commands = expand(commands, env);
		commands = remove_quotes(commands);
		redirect_and_execute(commands, &env);
	}
	return (0);
}
