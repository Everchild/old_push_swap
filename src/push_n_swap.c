/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:10:15 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/08 13:08:13 by sbrochar         ###   ########.fr       */
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

static int			find_n_smallest(t_clist **list, size_t n, t_bool small)
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

/*		cur = n_smallest->start;
		while (cur)
		{
		ft_printf("%d\n", *((int *)(cur->content)));
		cur = cur->next;
		}*/

	ret = *((int *)(n_smallest->end->content));
	free_dblist(&n_smallest);
	return (ret);
}

void				push_n_swap(t_clist **a, t_clist **b, size_t nb_elem)
{
	size_t			n;
	size_t			rest;
	int				n_to_push;

	//check cas particuliers
	//n = 10 * nb_elem / 100;

	n = 0;
	if (nb_elem == 3)
		ft_printf("3 elem");
	else if (nb_elem == 5)
		ft_printf("5 elem");
	else
	{
		if (nb_elem > 200)
		{
			n = nb_elem / 4;
			while (n > (20 * nb_elem / 100))
			{
				while ((*a)->nb_nodes > n)
				{
					n_to_push = find_n_smallest(a, n, B_TRUE);
					push_n_smallest_b(a, b, n, n_to_push, B_TRUE);
				}
				rest = (*a)->nb_nodes;
				n_to_push = find_n_smallest(a, n, B_TRUE);
				push_n_smallest_b(a, b, rest, n_to_push, B_TRUE);
				n /= 4;
				while ((*b)->nb_nodes > n)
				{
					n_to_push = find_n_smallest(b, n, B_FALSE);
					push_n_biggest_a(a, b, n, n_to_push);
				}
				rest = (*b)->nb_nodes;
				n_to_push = find_n_smallest(b, n, B_FALSE);
				push_n_biggest_a(a, b, rest, n_to_push);
				n /= 4;
			}
		}
		if (!n)
			n = 20 * nb_elem / 100;
		while ((*a)->nb_nodes > n)
		{
			n_to_push = find_n_smallest(a, n, B_TRUE);
			if (nb_elem > 200)
				push_n_smallest_b(a, b, n, n_to_push, B_FALSE);
			else
				push_n_smallest_b(a, b, n, n_to_push, B_TRUE);
		}
		rest = (*a)->nb_nodes;
		n_to_push = find_n_smallest(a, n, B_TRUE);
		push_n_smallest_b(a, b, rest, n_to_push, B_FALSE);
		insert_in_a(a, b, rest, n);
	}
}
