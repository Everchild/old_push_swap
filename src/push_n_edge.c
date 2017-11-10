/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_edge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:42:35 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/10 18:42:42 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void			insert_biggest_node(t_dblist **n_smallest, int i, size_t n)
{
	t_node			*node;
	t_node			*cur;

	cur = (*n_smallest)->start;
	node = create_node(NULL, 0);
	if (node)
		node->content = (int *)ft_memalloc(sizeof(int));
	if (node && node->content)
	{
		*((int *)(node->content)) = i;
		while (cur && *((int *)(cur->content)) > i)
			cur = cur->next;
		if (cur)
			dbinsert_node(n_smallest, node, cur);
		else if (!cur && (*n_smallest)->nb_nodes < n)
			dbadd_node_end(n_smallest, node);
		if ((*n_smallest)->nb_nodes > n)
			dbremove_node(n_smallest, (*n_smallest)->end);
	}
}

static void			insert_smallest_node(t_dblist **n_smallest, int i, size_t n)
{
	t_node			*node;
	t_node			*cur;

	cur = (*n_smallest)->start;
	node = create_node(NULL, 0);
	if (node)
		node->content = (int *)ft_memalloc(sizeof(int));
	if (node && node->content)
	{
		*((int *)(node->content)) = i;
		while (cur && *((int *)(cur->content)) < i)
			cur = cur->next;
		if (cur)
			dbinsert_node(n_smallest, node, cur);
		else if (!cur && (*n_smallest)->nb_nodes < n)
			dbadd_node_end(n_smallest, node);
		if ((*n_smallest)->nb_nodes > n)
			dbremove_node(n_smallest, (*n_smallest)->end);
	}
}

int					find_n_edge(t_clist **list, size_t n, t_bool small)
{
	t_dblist		*n_smallest;
	t_node			*cur;
	int				ret;

	n_smallest = create_dblist();
	cur = (*list)->start;
	ret = 0;
	if (n_smallest)
	{
		while (cur != (*list)->end)
		{
			if (small)
				insert_smallest_node(&n_smallest, *((int *)(cur->content)), n);
			else
				insert_biggest_node(&n_smallest, *((int *)(cur->content)), n);
			cur = cur->next;
		}
		if (small)
			insert_smallest_node(&n_smallest, *((int *)(cur->content)), n);
		else
			insert_biggest_node(&n_smallest, *((int *)(cur->content)), n);
	}
	ret = *((int *)(n_smallest->end->content));
	free_dblist(&n_smallest);
	return (ret);
}
