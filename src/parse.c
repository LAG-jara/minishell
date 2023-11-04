/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:09:34 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/04 13:48:18 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tokens.h"

// Returns TRUE if the redirection token in the 'i'th position is valid,
// returns FALSE otherwise.
static int	is_valid_redir(char **tokens, int i, int tok_amount)
{
	char	*next_tok;

	if (i + 1 >= tok_amount)
		return (FALSE);
	next_tok = tokens[i + 1];
	if (token_type(next_tok) == WORD)
		return (TRUE);
	else
		return (FALSE);
}

// Returns TRUE if the control token in the 'i'th position is valid,
// returns FALSE otherwise.
static int	is_valid_ctrl(char **tokens, int i, int tok_amount)
{
	char	*prev_tok;
	char	*next_tok;

	if (i + 1 >= tok_amount || i == 0)
		return (FALSE);
	next_tok = tokens[i + 1];
	prev_tok = tokens[i - 1];
	if (token_type(prev_tok) == WORD
		&& (token_type(next_tok) == WORD || token_type(next_tok) == REDIR))
		return (TRUE);
	else
		return (FALSE);
}

// Returns the amount of commands in the NULL-terminated 'tokens' array.
// If a syntax error is found, prints an error message and returns -1.
static int	count_commands_checking_syntax(char **tokens)
{
	int		tok_amount;
	int		cmd_amount;
	int		i;

	tok_amount = arrstr_size(tokens);
	cmd_amount = 1;
	i = 0;
	while (i < tok_amount)
	{
		if (token_type(tokens[i]) == REDIR
			&& !is_valid_redir(tokens, i, tok_amount))
			return (print_err_syntax(tokens[i], -1));
		if (token_type(tokens[i]) == PIPE)
		{
			++cmd_amount;
			if (!is_valid_ctrl(tokens, i, tok_amount))
				return (print_err_syntax(tokens[i], -1));
		}
		if (token_type(tokens[i]) == INVALID)
			return (print_err_syntax(tokens[i], -1));
		++i;
	}
	return (cmd_amount);
}

static t_list	*get_cmd(t_list **cmd, char **tokens, int *j)
{
	t_token	tok;
	int		i;

	i = 0;
	*cmd = NULL;
	while (tokens[++(*j)])
	{
		tok = token_create(tokens[*j]);
		if (tok.type != PIPE)
		{
			lst_add(cmd, lst_new(&tok, sizeof(tok)));
		}
		else
			return (*cmd);
	}
	return (*cmd);
}

// Parses the array of tokens and groups them into an array of commands,
// dividing them by the token '|'. Allocates and returns the array of commands.
// If a syntax error is found, prints an error message,
// 'errno' is set to the corresponding value and returns NULL.
t_list	**parse(char **tokens, int	*exit_status)
{
	int		cmd_amount;
	t_list	**cmds;
	int		i;
	int		j;

	cmd_amount = count_commands_checking_syntax(tokens);
	if (cmd_amount == -1)
	{
		*exit_status = ERRNO_SYNTAX;
		return (NULL);
	}
	cmds = (t_list **) p_malloc(sizeof(t_list *) * (cmd_amount + 1));
	j = -1;
	i = -1;
	while (++i < cmd_amount)
		get_cmd(&cmds[i], tokens, &j);
	cmds[i] = NULL;
	return (cmds);
}

# include "debug.h"
# include "print_fx.h"

// int	main(void)
// {
// 	// char *pre_toks[] = \
// 	// { "ls", "arg1", "|", "|", "echo", "Holis", ":)", ">", "outfile", NULL};

// 	// t_list	**cmds;
// 	// cmds = parse(pre_toks);
// 	// if (cmds)
// 	// 	print_cmds(cmds);

// 	t_list	*lst = NULL;
// 	// t_list	*lst2 = NULL;

// 	char	*str = ft_strdup("hola");
// 	lst_add(&lst, lst_new(&str, sizeof(str)));
// 	str = ft_strdup("holis");
// 	lst_add(&lst, lst_new(&str, sizeof(str)));
// 	str = ft_strdup("ciao");
// 	lst_add(&lst, lst_new(&str, sizeof(str)));
// 	print_lst(lst, pr_str);

// 	printf("\n-------------------------\n\n");

// 	lst_rm_many(&lst, lst->nxt->nxt, 2, free);
// 	print_lst(lst, pr_str);


// 	// lst_add_many(&lst, lst->nxt, lst2);
// 	// print_lst(lst, pr_str);

// 	// t_token	tok = token_create("hola'que\"tal\"?");
// 	// print_token(tok);
	

// 	// t_xtoken xtok = tok_to_xtok(&tok);
// 	// t_list *lst = xtok.val;
// 	// t_xchar *xc = (t_xchar *)lst->val;
// 	// xc->x = EXPANDED;
// 	// print_xtoken(xtok);

// 	// printf("\n-------------------------\n\n");
	
// 	// tok = xtok_to_tok(&xtok);
// 	// print_token(tok);

// 	// t_xchar	xc = xc_new('l', UNEXPANDED, UNQUOTED);
// 	// xtok_rm_xcs(&xtok, &xc);
// 	// print_xtoken(xtok);
// }
