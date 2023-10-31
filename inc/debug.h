
#ifndef DEBUG_H
# define DEBUG_H

# include <stdio.h>
# include "list.h"
# include "token_utils.h"
# include "xtoken.h"

void	print_arrint(int *arr);
void	print_arrstr(char **arr);

void	print_token(t_token tok);
void	print_xtoken(t_xtoken xtok);

void	print_lst(t_list *node, void (*pr_funct)(void *));
void	pr_str(void *str);
void	pr_token(void *tok);
void	pr_xchar(void *xchar);

void	print_cmds(t_list **cmds);

#endif
