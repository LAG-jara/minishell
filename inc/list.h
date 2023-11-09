/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:13:02 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/30 16:18:19 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_list
{
	void			*val;
	struct s_list	*nxt;
	struct s_list	*pre;
}	t_list;

size_t	lst_size(t_list *lst);
t_list	*lst_new(void *value, size_t size);
t_list	*lst_last(t_list *lst);
t_list	*lst_first(t_list *lst);
t_list	*lst_move(t_list *node, int n);
void	lst_add(t_list **lst, t_list *to_add);
void	lst_add_many(t_list **lst, t_list *pos, t_list *to_add);
void	lst_clear(t_list **lst, void (*del)(void *));
void	lst_delone(t_list *lst, void (*del)(void *));
void	lst_link(t_list *n1, t_list *n2);
void	lst_rm_one(t_list **lst, t_list *to_rm, void (*del)(void *));
void	lst_rm_many(t_list **lst, t_list *to_rm, size_t n, void (*del)(void *));
void	lst_split(t_list *node);

#endif
