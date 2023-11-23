/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_and_execute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:23:44 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/23 15:33:09 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirect_and_execute.h"

# include "debug.h"

// Redirects and executes the given command 'cmd' on the current shell
// environment, returning the exit status.
static int	process_builtin_here(t_list *cmd, int exit_status, char ***env)
{
	int		exit_stat;

	exit_stat = redirect(&cmd, *env);
	if (exit_stat != 0)
		return (exit_stat);
	ft_putendl_fd("redirection OK", STDERR_FILENO);
	if (lst_size(cmd) > 0)
		exit_stat = execute_builtin(cmd, exit_status, env);
	return (exit_stat);
}

// Redirects and executes the command 'cmd' in a subshell, taking into account
// it is the i-th command of the pipeline.
// It exits with the appropriate exit status, or returns with a non-zero value.
static int	process_command(t_pipe *p, int i, t_list *cmd, int e_stat, char **env)
{
	int		exit_stat;

	exit_stat = redirect(&cmd, env);
	if (exit_stat != 0)
		exit(exit_stat);
	if (i > 0)
		link_read_end(p->prev_fds);
	if (i < p->cmds_amount - 1)
		link_write_end(p->next_fds);
	if (lst_size(cmd) == 0)
		exit(EXIT_SUCCESS);
	execute_command(cmd, e_stat, env);
	return (EXIT_FAILURE);
}

// Updates the pipe's file descriptor updates from the parent process for the 
// i-th command, closing previous file descriptors and preparing for next.
static void	parent_pipe_update(t_pipe *p, int i)
{
	if (i > 0)
	{
		close(p->prev_fds[READ_END]);
		close(p->prev_fds[WRITE_END]);
	}
	if (i < p->cmds_amount - 1)
	{
		p->prev_fds[READ_END] = p->next_fds[READ_END];
		p->prev_fds[WRITE_END] = p->next_fds[WRITE_END];
	}
}

// Redirects and executes the commands defined by the array of commands 'cmds',
// assuming p->cmds_amount is already initialized. All commands are executed in
// subprocesses. Returns the exit status of the last command.
static int	process_commands(t_list **cmds, t_pipe *p, int e_stat, char **env)
{
	int		i;
	pid_t	pid;
	pid_t	last_child;

	i = 0;
	while (i < p->cmds_amount)
	{
		if (i < p->cmds_amount - 1)
			pipe_or_die(p->next_fds);
		pid = fork_or_die();
		if (pid == 0)
			return (process_command(p, i, cmds[i], e_stat, env));
		parent_pipe_update(p, i);
		last_child = pid;
		i++;
	}
	return (wait_children(last_child, p->cmds_amount));
}

// Performs all redirections and command/builtin executions defined by the array
// of lists 'commands', updating the 'exit_status' and environment 'env'
// accordingly.
void	redirect_and_execute(t_list **commands, int *exit_status, char ***env)
{
	t_pipe	p;

	p.cmds_amount = arr_size((void *)commands);
	if (p.cmds_amount == 1 && is_builtin_cmd(commands[0]))
		*exit_status = process_builtin_here(commands[0], *exit_status, env);
	else
		*exit_status = process_commands(commands, &p, *exit_status, *env);
}

// # include "debug.h"
// # include "parse_tokens.h"
// # include "tokenize.h"
// # include "expand_and_split.h"

// int	main(int ac, char **av, char **e)
// {
// 	av++;
// 	ac--;
// 	char **env = arrstr_dup(e);
// 	int exit_status;
// 	char *input = "ls";

// 	t_list	*tokens = tokenize(input);
// 	// printf("\n___________________TOKENIZE\n");
// 	// print_lst(tokens, pr_token);


// 	t_list	**cmds;
// 	cmds = parse(tokens, &exit_status);
// 	printf("\n______________________PARSE\n");
// 	if (cmds)
// 		print_cmds(cmds);
// 	printf("Exit status: %d\n", exit_status);


// 	cmds = expand_and_split(cmds, exit_status, env);
// 	printf("\n___________EXPAND AND SPLIT\n");
// 	print_cmds(cmds);
	
// 	env_free(env);
// 	lst_clear(cmds, tok_del);
// 	free(cmds);
// }