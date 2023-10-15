/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_strarr2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:01:55 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/15 13:39:57 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

// Counts and returns the amount of strings in the NULL-terminated array 'arr'.
static size_t	get_arr2_size(char **arr)
{
	size_t	size;

	size = 0;
	while (arr[size])
		++size;
	return (size);
}

// Safely allocates and returns a copy of 'str'.
// Exits properly is memory allocation fails.
static char	*strdup_exit(char *str)
{
	char	*new_str;

	new_str = ft_strdup(str);
	if (new_str == NULL)
		exit (1);
	return (new_str);
}

// Allocates and returns a copy of the NULL-terminated array of strings 'arr'
// with the string 'str' added at the end of it.
// The original array 'arr' is freed.	// TODO: Check free
char	**add_strarr2(char *str, char **arr)
{
	char	**new_arr;
	size_t	orig_arr_size;
	int		i;

	orig_arr_size = get_arr2_size(arr);
	new_arr = (char **) malloc(sizeof(char *) * (orig_arr_size + 2));
	i = -1;
	while (arr[++i])
		new_arr[i] = strdup_exit(arr[i]);
	new_arr[i] = strdup_exit(str);
	new_arr[i + 1] = NULL;
	// free_strarr2(arr);
	return (new_arr);
}

// Sets the value of the 'i'th string in the NULL-terminated array 'arr' of
// strings to the string 'str'. Returns 'arr'.
// Pre: 'i' must be smaller than the 'arr' size.
char	**set_strarr2(char *str, char **arr, int i)
{
	//free(arr[i]);				// TODO: Check free
	arr[i] = strdup_exit(str);
	return (arr);
}

// Allocates and returns a copy of the NULL-terminated array of strings 'arr'
// with the 'i'th string removed from it.
// The original array 'arr' is freed.	// TODO: Check free
char	**rm_strarr2(char **arr, int i)
{
	char	**old_arr;
	char	**new_arr;
	size_t	orig_arr_size;
	int		j;

	old_arr = arr;
	orig_arr_size = get_arr2_size(old_arr);
	new_arr = (char **) malloc(sizeof(char *) * orig_arr_size);
	j = -1;
	while (old_arr[++j])
	{
		if (j == i)
			++old_arr;
		new_arr[j] = strdup_exit(old_arr[j]);
	}
	new_arr[j] = NULL;
	// free_strarr2(arr);
	return (new_arr);
}


// #include <printf.h>
// void	print_arrstr2(char **arr)
// {
// 	int i = 0;
// 	while (arr[i])
// 	{
// 		printf("[%d] : %s\n", i, arr[i]);
// 		++i;
// 	}
// }

// int	main(int ac, char **av, char **env)
// {
// 	printf("ORIGINAL:\n\n");
// 	print_arrstr2(env);

// 	int index = 5;
// 	char *str = "Patata frita ✅";

// 	// printf("\n\nRemoving element [%d]...\n", index);
// 	// env = rm_strarr2(env, index);

// 	// printf("\n\Setting element [%d]...\n", index);
// 	// env = set_strarr2("Patata frita ✅", env, index);

// 	printf("\n\nAdding element '%s'...\n", str);
// 	env = add_strarr2(str, env);

// 	printf("NEW:\n\n");
// 	print_arrstr2(env);
// }