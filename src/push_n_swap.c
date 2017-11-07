/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:10:15 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/07 13:42:17 by sbrochar         ###   ########.fr       */
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

static t_bool		choose_rotating_way(t_clist **a, int n_smallest)
{
	size_t			check_ra;
	size_t			check_rra;
	t_node			*cur;

	check_ra = 0;
	check_rra = 0;
	cur = (*a)->start;
	while (*((int *)(cur->content)) > n_smallest)
	{
		cur = cur->next;
		check_ra++;
	}
	cur = (*a)->start;
	while (*((int *)(cur->content)) > n_smallest)
	{
		cur = cur->prev;
		check_rra++;
	}
	return (check_ra < check_rra);
}

static void			push_n_smallest(t_clist **a, t_clist **b, size_t n, int	n_smallest, t_bool isa, t_bool first)
{
	size_t			i;
	t_bool			ra;

	i = 0;
	if (isa)
	{
		while (i < n)
		{
			if (first)
				ra = 1;
			else
				ra = choose_rotating_way(a, n_smallest);
			while (*((int *)((*a)->start->content)) > n_smallest)
			{
				if (ra)
					rotate_a(a, b, B_TRUE);
				else
					reverse_rotate_a(a, b, B_TRUE);
			}
			push_b(a, b, B_TRUE);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			ra = choose_rotating_way(b, n_smallest);
			while (*((int *)((*b)->start->content)) > n_smallest)
			{
				if (ra)
					rotate_b(a, b, B_TRUE);
				else
					reverse_rotate_b(a, b, B_TRUE);
			}
			push_a(a, b, B_TRUE);
			i++;
		}
	}
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
			while (n > (10 * nb_elem / 100))
			{
				while ((*a)->nb_nodes > n)
				{
					n_smallest = find_n_smallest(a, n);
					push_n_smallest(a, b, n, n_smallest, B_TRUE, B_TRUE);
				}
				rest = (*a)->nb_nodes;
				n_smallest = find_n_smallest(a, n);
				push_n_smallest(a, b, rest, n_smallest, B_TRUE, B_TRUE);
				n /= 4;
				while ((*b)->nb_nodes > n)
				{
					n_smallest = find_n_smallest(b, n);
					push_n_smallest(a, b, n, n_smallest, B_FALSE, B_FALSE);
				}
				rest = (*b)->nb_nodes;
				n_smallest = find_n_smallest(b, n);
				push_n_smallest(a, b, rest, n_smallest, B_FALSE, B_FALSE);
				n /= 4;
			}
		}
		if (!n)
			n = 18 * nb_elem / 100;
		while ((*a)->nb_nodes > n)
		{
			n_smallest = find_n_smallest(a, n);
			if (nb_elem > 200)
				push_n_smallest(a, b, n, n_smallest, B_TRUE, B_FALSE);
			else
				push_n_smallest(a, b, n, n_smallest, B_TRUE, B_TRUE);
		}
		rest = (*a)->nb_nodes;
		n_smallest = find_n_smallest(a, n);
		push_n_smallest(a, b, rest, n_smallest, B_TRUE, B_FALSE);
		insert_in_a(a, b, rest, n);
	}
}
