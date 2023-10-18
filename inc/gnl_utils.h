/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:42:58 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/18 17:48:26 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_UTILS_H
# define GNL_UTILS_H

# include <stdlib.h>

char	*gnl_strjoin_free(char *s1, char *s2);
char	*gnl_substr(char const *s, unsigned int start, size_t len);

#endif