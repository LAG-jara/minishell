/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:13:02 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/27 18:59:00 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H

# include <stdlib.h>

typedef struct s_lst
{
	void	*val;
	t_lst	*nxt;
	t_lst	*pre;
}	t_lst;

void	lst_add(t_lst **lst, t_lst *new);
void	lst_clear(t_lst **lst, void (*del)(void *));
void	lst_delone(t_lst *lst, void (*del)(void *));
t_lst	*lst_last(t_lst *lst);
void	lst_link(t_lst *n1, t_lst *n2);
t_lst	*lst_new(void *value);
void	lst_rm(t_lst **lst, t_lst *to_rm, void (*del)(void *));
size_t	lst_size(t_lst *lst);

// DEPRECATED: Use 'lst_rm_node'
t_lst *rm_node_at(t_lst *start, t_lst *to_delete);

#endif