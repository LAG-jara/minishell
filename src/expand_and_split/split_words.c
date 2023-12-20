/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:14:14 by glajara-          #+#    #+#             */
/*   Updated: 2023/12/20 12:29:58 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xtoken.h"
#include "boolean.h"
#include "quote_utils.h"
#include "input_utils.h"

// Returns TRUE if the value of 'xc_node' is a blank char (space or tab) that 
// is also expanded and non-double-quoted.
static int	is_delim(t_xchar xc)
{
	if (is_blankchr(xc.c) && xc.x == EXPANDED && xc.q != DQUOTED)
		return (TRUE);
	return (FALSE);
}

// Removes and frees all blank elements from 'xc_lst' that are also expanded
// and non-double-quoted, until the first that don't comply all conditions.
static void	rm_first_delims(t_list **xc_lst)
{
	t_list	*xc_node;
	t_list	*next_node;

	xc_node = *xc_lst;
	while (xc_node && is_delim(xc_get(xc_node)))
	{
		next_node = xc_node->nxt;
		lst_rm_one(xc_lst, xc_node, free);
		xc_node = next_node;
	}
	*xc_lst = xc_node;
}

// Starting from 'xc_lst', pops the first word, returning it as an xtoken of
// type WORD. At the end, 'xc_lst' points to the xchar right after the word.
// If there is no word to pop, returns NULL.
static t_xtoken	pop_word(t_list **xc_lst)
{
	t_list		*xc;
	t_xtoken	xtok;

	rm_first_delims(xc_lst);
	xtok.val = NULL;
	xtok.type = WORD;
	if (!*xc_lst)
		return (xtok);
	xc = *xc_lst;
	while (xc && !is_delim(xc_get(xc)))
	{
		xtok_addxc(&xtok, xc_get(xc));
		xc = xc->nxt;
	}
	lst_rm_many(xc_lst, *xc_lst, lst_size(xtok.val), free);
	return (xtok);
}

// Given the 'xtoken' node of the 'xtokens' list, perform word_splitting on it.
// Unquoted implicit null tokens are removed.
// At the end, 'xtoken' points to the next element of the list.
static void	split_words_xtok(t_list **xtokens, t_list **xtoken)
{
	t_xtoken	split_word;
	t_list		*split_words;
	t_list		*next_node;
	t_xtoken	*xtok_orig;

	xtok_orig = xtok_get(*xtoken);
	next_node = (*xtoken)->nxt;
	split_words = NULL;
	split_word = pop_word(&xtok_orig->val);
	while (split_word.val)
	{
		lst_add(&split_words, lst_new(&split_word, sizeof(split_word)));
		split_word = pop_word(&xtok_orig->val);
	}
	lst_rm_one(xtokens, *xtoken, free);
	lst_add_many(xtokens, next_node, split_words);
	*xtoken = next_node;
}

// Receives a list of xtokens and performs word splitting on the
// non-double-quoted expanded parts of words.
// Unquoted implicit null tokens are removed.
void	split_words(t_list **xtokens)
{
	t_list		*node;

	node = *xtokens;
	while (node)
	{
		if (xtok_get(node)->type == WORD)
			split_words_xtok(xtokens, &node);
		else
			node = node->nxt;
	}
}
