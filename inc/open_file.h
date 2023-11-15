/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:48:50 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/15 17:35:30 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_FILE_H
# define OPEN_FILE_H

# include "basic_utils.h"	// using: putstr_fd
# include <errno.h>			// using: errno
# include <fcntl.h>			// using: open()
# include "minish_consts.h"	// using: SH_NAME
# include <string.h>		// using: strerror()
# include <unistd.h>		// using: STDERR_FILENO

int	open_file(const char *filename, int flags);

#endif