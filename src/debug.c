

#include "debug.h"

// DEBUG ONLY! 
void	print_arrint(int *arr)
{
	int	i;

	i = -1;
	while (arr[++i] != -1)
		printf("[%d] : %d\n", i, arr[i]);
}

// DEBUG ONLY!
void	print_arrstr(char **arr)
{
	int	i;

	i = -1;
	while (arr && arr[++i])
		printf("[%d] : %s\n", i, arr[i]);
}

// DEBUG ONLY!
void	print_lst(t_lst *node, void (*pr_funct)(void *))
{
	int	i;

	i = 0;
	while (node)
	{
		printf("(%d): ", i++);
		(*pr_funct)(node->val);
		node = node->nxt;
	}
}

// DEBUG ONLY!
void	pr_str(void *str)
{
	printf("%s\n", *(char **)str);
}

// DEBUG ONLY!
void	pr_token(void *token)
{
	char	*type;
	t_token tok;


	tok = *(t_token *)token;
	if (tok.type == WORD)
		type = "WORD";
	else if (tok.type == REDIR)
		type = "REDIR";
	else if (tok.type == PIPE)
		type = "PIPE";
	else
		type = "INVALID";
	printf("%s\t%s\n", type, tok.val);
}

// DEBUG ONLY!
void	print_cmds(t_lst **cmds)
{
	int	i;

	i = -1;
	while (cmds[++i])
	{
		printf("COMMAND #%d\n", i);
		print_lst(cmds[i], pr_token);
		printf("\n");
	}
}
