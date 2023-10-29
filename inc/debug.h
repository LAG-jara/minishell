

#ifndef DEBUG_H
# define DEBUG_H

# include <stdio.h>

void	print_arrint(int *arr);
void	print_arrstr(char **arr);

void	lst_print(t_lst *node, void (*pr_funct)(void *));
void	pr_str(void *str);
void	pr_token(void *tok);
void	print_cmds(t_lst **cmds);

#endif