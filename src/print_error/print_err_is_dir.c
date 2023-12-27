/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_exec copy 4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:11:53 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/27 16:39:30 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_error.h"
#include "basic_utils.h"
#include "minish_consts.h"
#include <unistd.h>

// Prints an error message when the given path is a directory.
void	print_err_is_dir(const char *path)
{
	ft_putstr_fd(SH_NAME, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(MSG_IS_DIR, STDERR_FILENO);
}
