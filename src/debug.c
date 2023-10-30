

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
void	print_token(t_token tok)
{
	char	*type;

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
void	print_xtoken(t_xtoken xtok)
{
	char	*type;
	t_list	*node;

	if (xtok.type == WORD)
		type = "WORD";
	else if (xtok.type == REDIR)
		type = "REDIR";
	else if (xtok.type == PIPE)
		type = "PIPE";
	else
		type = "INVALID";
	printf("%s\t", type);
	node = xtok.val;
	while (node)
	{
		t_xchar xc = *(t_xchar *)node->val;
		printf("%c", xc.c);
		node = node->nxt;
	}
	printf("\n exp\t");
	node = xtok.val;
	while (node)
	{
		t_xchar xc = *(t_xchar *)node->val;
		printf("%d", xc.x);
		node = node->nxt;
	}
	printf("\n quo\t");
	node = xtok.val;
	while (node)
	{
		t_xchar xc = *(t_xchar *)node->val;
		printf("%d", xc.q);
		node = node->nxt;
	}
	printf("\n");
}

// DEBUG ONLY!
void	print_lst(t_list *node, void (*pr_funct)(void *))
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
	print_token(*(t_token *)token);
}

// DEBUG ONLY!
void	print_cmds(t_list **cmds)
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
