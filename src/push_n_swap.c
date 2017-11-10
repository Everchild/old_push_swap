/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:10:15 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/10 17:41:47 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static t_bool		is_sorted(t_clist *a)
{
	t_node			*cur;

	cur = a->start;
	while (cur != a->end)
	{
		if (*((int *)(cur->content)) > *((int *)(cur->next->content)))
			return (B_FALSE);
		cur = cur->next;
	}
	return (B_TRUE);
}

static size_t		more_than_two_hundreds(t_stacks *stacks, size_t n,
					size_t nb_elem, size_t rest)
{
	int				n_to_push;

	n = nb_elem / 4;
	while (n > (20 * nb_elem / 100))
	{
		while (stacks->a->nb_nodes > n)
		{
			n_to_push = find_n_edge(&(stacks->a), n, B_TRUE);
			push_n_smallest_b(stacks, n, n_to_push, B_TRUE);
		}
		rest = stacks->a->nb_nodes;
		n_to_push = find_n_edge(&(stacks->a), n, B_TRUE);
		push_n_smallest_b(stacks, rest, n_to_push, B_TRUE);
		n /= 4;
		while (stacks->b->nb_nodes > n)
		{
			n_to_push = find_n_edge(&(stacks->b), n, B_FALSE);
			push_n_biggest_a(&(stacks->a), &(stacks->b), n, n_to_push);
		}
		rest = stacks->b->nb_nodes;
		n_to_push = find_n_edge(&(stacks->b), n, B_FALSE);
		push_n_biggest_a(&(stacks->a), &(stacks->b), rest, n_to_push);
		n /= 4;
	}
	return (n);
}

static void			handle_big_lists(size_t n, size_t nb_elem, t_stacks *stacks)
{
	size_t			rest;
	int				n_to_push;

	if (!n)
		n = 20 * nb_elem / 100;
	while (stacks->a->nb_nodes > n)
	{
		n_to_push = find_n_edge(&(stacks->a), n, B_TRUE);
		if (nb_elem > 200)
			push_n_smallest_b(stacks, n, n_to_push, B_FALSE);
		else
			push_n_smallest_b(stacks, n, n_to_push, B_TRUE);
	}
	rest = stacks->a->nb_nodes;
	n_to_push = find_n_edge(&(stacks->a), n, B_TRUE);
	push_n_smallest_b(stacks, rest, n_to_push, B_FALSE);
	insert_in_a(&(stacks->a), &(stacks->b), rest, n);
}

void				push_n_swap(t_stacks *stacks, size_t nb_elem)
{
	size_t			n;
	size_t			rest;

	n = 0;
	rest = 0;
	if (!is_sorted(stacks->a))
	{
		if (nb_elem <= 6)
			handle_small_lists(stacks, nb_elem);
		else
		{
			if (nb_elem > 200)
				n = more_than_two_hundreds(stacks, n, nb_elem, rest);
			handle_big_lists(n, nb_elem, stacks);
		}
	}
}
