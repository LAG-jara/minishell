/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:48:50 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/16 14:07:43 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_FILE_H
# define OPEN_FILE_H

# include <fcntl.h>
# include "print_error.h"

# define OPEN_FILE_MODE 0644

int	open_file(const char *filename, int flags);

#endif
