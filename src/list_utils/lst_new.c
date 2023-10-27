/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:13:59 by glajara-          #+#    #+#             */
/*   Updated: 2023/10/27 18:58:45 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"

// Allocates (with malloc(3)) and returns a new node.
// The member variable 'val' is initialized with the value of the parameter
// 'value'. The variables 'nxt' and 'pre' is initialized to NULL.
t_lst	*lst_new(void *value)
{
	t_lst	*lstnode;

	lstnode = (t_lst *) malloc(sizeof (t_lst));
	if (lstnode == NULL)
		return (NULL);
	lstnode->val = value;
	lstnode->nxt = NULL;
	lstnode->pre = NULL;
	return (lstnode);
}
