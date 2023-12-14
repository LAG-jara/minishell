

#include "debug.h"
#include "quote_utils.h"
#include "token.h"
#include "xtoken.h"
#include "print_fx.h"
#include <stdio.h>

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
		type = "WRONG";
	printf("%s\t%s\n", type, tok.val);
}

// DEBUG ONLY!
void	print_xtoken(t_xtoken xtok)
{
	char	*type;

	if (xtok.type == WORD)
		type = "WORD_";
	else if (xtok.type == REDIR)
		type = "REDIR_";
	else if (xtok.type == PIPE)
		type = "PIPE_";
	else
		type = "WRONG_";
	printf("%s\t", type);
	print_lst(xtok.val, pr_xchar);
	printf("\n");
}

// DEBUG ONLY!
void	print_lst(t_list *node, void (*pr_funct)(void *))
{
	// int	i;

	// i = 0;
	while (node)
	{
		// printf("(%d): ", i++);
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
void	pr_xtoken(void *xtoken)
{
	print_xtoken(*(t_xtoken *)xtoken);
}

// DEBUG ONLY!
void	pr_xchar(void *xchar)
{
	t_xchar	xc;
	char	*color;
	char	*style;

	xc = *(t_xchar *)xchar;
	style = PFX_NORMAL;
	if (xc.x == EXPANDED)
		style = PFX_ULINE;
	color = PFX_CWHITE;
	if (xc.q == QUOTED)
		color = PFX_CBLUE;
	else if (xc.q == DQUOTED)
		color = PFX_CGREEN;
	printf("%s%s;%s%s%c%s",
		PFX_PREFIX, style, color, PFX_AFFIX, xc.c, PFX_SET_DEFAULT);
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
