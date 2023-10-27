/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:13:59 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/27 14:15:30 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xlist.h"

// Allocates (with malloc(3)) and returns a new node.
// The member variable ’content’ is initialized with the value of the parameter
// ’content’. The variable ’next’ is initialized to NULL.
t_lst	*ft_lstnew(void *content)
{
	t_lst	*lstnode;

	lstnode = (t_lst *) malloc(sizeof (t_lst));
	if (lstnode == NULL)
		return (NULL);
	lstnode->val = content;
	lstnode->nxt = NULL;
	return (lstnode);
}