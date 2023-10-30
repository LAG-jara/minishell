/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:13:02 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/30 12:47:58 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H

# include <stdlib.h>

typedef struct s_list
{
	void			*val;
	struct s_list	*nxt;
	struct s_list	*pre;
}	t_list;

void	lst_add(t_list **lst, t_list *new);
void	lst_clear(t_list **lst, void (*del)(void *));
void	lst_delone(t_list *lst, void (*del)(void *));
t_list	*lst_last(t_list *lst);
void	lst_link(t_list *n1, t_list *n2);
t_list	*lst_new(void *value, size_t size);
void	lst_rm(t_list **lst, t_list *to_rm, void (*del)(void *));
size_t	lst_size(t_list *lst);

#endif
