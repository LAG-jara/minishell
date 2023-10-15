/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:00:59 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/15 12:03:11 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_INPUT_H
# define GET_INPUT_H

# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT "minish$ "

char	*get_input(void);

#endif