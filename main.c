/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alajara- <alajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:55:53 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/14 13:50:33 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av, char **env)
{
	char	*input;
	char	**tokens;
	char	***commands;
	int		exit_status;

	while (42)
	{
		input = get_input(env);
		tokens = tokenize(input);
		commands = parse(tokens);
		commands = expand(commands, env);
		commands = remove_quotes(commands);
		commands = redirect(commands, env);
		exit_status = execute(commands, &env);
		set_exit_status(exit_status, &env);
	}
	return (exit_status);
}
