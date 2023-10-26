

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
void	print_cmds(char ***cmds)
{
	int	i;

	i = 0;
	while (cmds && cmds[i])
	{
		printf("CMD %d:\n", i);
		print_arrstr(cmds[i]);
		printf("\n");
		++i;
	}
}
