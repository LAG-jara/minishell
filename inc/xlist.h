/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:13:46 by alajara-          #+#    #+#             */
/*   Updated: 2023/10/27 17:28:36 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XLIST_H
# define XLIST_H

# include <stdlib.h>

typedef struct s_lst
{
	void	*val;
	t_lst	*nxt;
	t_lst	*pre;
} t_lst;

typedef struct s_xchar
{
	char	c;
	int		x : 1;
	int		q : 2;
} t_xchar;

void	ft_lstclear(t_lst **lst, void (*del)(void*));
void	ft_lstdelone(t_lst *lst, void (*del)(void *));
t_lst	*ft_lstnew(void *content);
size_t	ft_lstsize(t_lst *lst);


#endif