/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:00:59 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/22 15:44:01 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_INPUT_H
# define GET_INPUT_H

# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT "\033[32mminish\033[33m$ \033[0m"

char	*get_input(void);

#endif