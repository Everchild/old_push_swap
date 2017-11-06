/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:10:15 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/06 17:22:14 by sbrochar         ###   ########.fr       */
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

static int			find_n_smallest(t_clist **a, size_t n)
{
	t_dblist		*n_smallest;
	t_node			*cur;
	int				ret;

	n_smallest = create_dblist();
	cur = (*a)->start;
	ret = 0;
	if (n_smallest)
	{
		while (cur != (*a)->end)
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

static void			push_n_smallest(t_clist **a, t_clist **b, size_t n, int	n_smallest)
{
	size_t			i;
	t_bool			ra;

	i = 0;
	while (i < n)
	{
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

void				push_n_swap(t_clist **a, t_clist **b, size_t nb_elem)
{
	size_t			n;
	size_t			rest;
	int				n_smallest;
	
	//check cas particuliers
	nb_elem = (size_t)nb_elem;
	n = 10 * nb_elem / 100;
	while ((*a)->nb_nodes > n)
	{
		n_smallest = find_n_smallest(a, n);
		push_n_smallest(a, b, n, n_smallest);
	}
	rest = (*a)->nb_nodes;
	n_smallest = find_n_smallest(a, n);
	push_n_smallest(a, b, rest, n_smallest);
	insert_in_a(a, b, rest, n);	
}
