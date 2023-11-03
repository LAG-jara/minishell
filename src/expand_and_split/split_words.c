/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glajara- <glajara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:14:14 by glajara-          #+#    #+#             */
/*   Updated: 2023/11/03 19:31:35 by glajara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_and_split.h"

# include "debug.h"

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
	while(xc_node && is_delim(xc_get(xc_node)))
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

	// printf("xc_lst after rmfirstdelims:\n");
	// print_lst(*xc_lst, pr_xchar);
	// printf("\n");

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

	// printf("xtok:	");
	// print_xtoken(xtok);

	lst_rm_many(xc_lst, *xc_lst, lst_size(xtok.val), free);

	// printf("final xc_lst:	");
	// print_lst(*xc_lst, pr_xchar);
	// printf("\n");

	// printf("RETURNING WORD:	");
	// print_xtoken(xtok);

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
	t_xtoken	xtok_orig;

	xtok_orig = xtok_get(*xtoken);
	next_node = (*xtoken)->nxt;
	split_words = NULL;

	// printf("\nCURRENT:");
	// print_xtoken(xtok_orig);
	// printf("NEXT:");
	// print_xtoken(xtok_get(next_node));
	// printf("xtokens:\n");
	// print_lst(*xtokens, pr_xtoken);
	// printf("\n\n");

	split_word = pop_word(&xtok_orig.val);
	while (split_word.val)
	{
		lst_add(&split_words, lst_new(&split_word, sizeof(split_word)));
		split_word = pop_word(&xtok_orig.val);
	}

	lst_rm_one(xtokens, *xtoken, free);	// TODO: xtok_del function

	// printf("split_words:\n");
	// print_lst(split_words, pr_xtoken);
	// printf("\n");

	// printf("xtokens:\n");
	// print_lst(*xtokens, pr_xtoken);
	// printf("\n");
	
	lst_add_many(xtokens, next_node, split_words);

	// printf("xtokens added:\n");
	// print_lst(*xtokens, pr_xtoken);
	// printf("\n");
	*xtoken = next_node;
}

// Receives a list of xtokens and performs word splitting on the non-double-
// quoted expanded parts of words. Unquoted implicit null tokens are removed.
void	split_words(t_list **xtokens)
{
	t_list		*node;

	node = *xtokens;
	while (node)
	{
		if (xtok_get(node).type == WORD)
			split_words_xtok(xtokens, &node);
		else
			node = node->nxt;
	}
}
