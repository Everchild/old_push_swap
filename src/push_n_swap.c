/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:10:15 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/07 17:44:55 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void			insert_sorted_node(t_dblist **n_smallest, int i, size_t n)
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

static int			find_n_smallest(t_clist **list, size_t n)
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
			insert_sorted_node(&n_smallest, *((int *)(cur->content)), n);
			cur = cur->next;
		}
		insert_sorted_node(&n_smallest, *((int *)(cur->content)), n);
	}

	/*	cur = n_smallest->start;
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
	int				n_smallest;

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
					n_smallest = find_n_smallest(a, n);
					push_n_smallest_b(a, b, n, n_smallest, B_TRUE);
				}
				rest = (*a)->nb_nodes;
				n_smallest = find_n_smallest(a, n);
				push_n_smallest_b(a, b, rest, n_smallest, B_TRUE);
				n /= 4;
				while ((*b)->nb_nodes > n)
				{
					n_smallest = find_n_smallest(b, n);
					push_n_smallest_a(a, b, n, n_smallest);
				}
				rest = (*b)->nb_nodes;
				n_smallest = find_n_smallest(b, n);
				push_n_smallest_a(a, b, rest, n_smallest);
				n /= 4;
			}
		}
		if (!n)
			n = 20 * nb_elem / 100;
		while ((*a)->nb_nodes > n)
		{
			n_smallest = find_n_smallest(a, n);
			if (nb_elem > 200)
				push_n_smallest_b(a, b, n, n_smallest, B_FALSE);
			else
				push_n_smallest_b(a, b, n, n_smallest, B_TRUE);
		}
		rest = (*a)->nb_nodes;
		n_smallest = find_n_smallest(a, n);
		push_n_smallest_b(a, b, rest, n_smallest, B_FALSE);
		insert_in_a(a, b, rest, n);
	}
}
