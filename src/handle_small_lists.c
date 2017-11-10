/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_small_lists.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:40:51 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/10 18:36:49 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void			sort_three_elem_b(t_clist **a, t_clist **b)
{
	t_node			*smallest;

	smallest = (*b)->start;
	if (*((int *)(smallest->content)) > *((int *)(smallest->next->content)))
		smallest = smallest->next;
	if (*((int *)(smallest->content)) > *((int *)((*b)->end->content)))
		smallest = (*b)->end;
	if (smallest == (*b)->start)
		rotate_b(a, b, B_TRUE);
	else if (smallest != (*b)->end)
		reverse_rotate_b(a, b, B_TRUE);
	if (*((int *)((*b)->start->content)) < *((int *)((*b)->start->next->content)))
		swap_b(a, b, B_TRUE);
}

static void			sort_three_elem(t_clist **a, t_clist **b, t_bool isa)
{
	t_node			*biggest;

	if (isa)
	{
		biggest = (*a)->start;
		if (*((int *)(biggest->content)) < *((int *)(biggest->next->content)))
			biggest = biggest->next;
		if (*((int *)(biggest->content)) < *((int *)((*a)->end->content)))
			biggest = (*a)->end;
		if (biggest == (*a)->start)
			rotate_a(a, b, B_TRUE);
		else if (biggest != (*a)->end)
			reverse_rotate_a(a, b, B_TRUE);
		if (*((int *)((*a)->start->content)) > *((int *)((*a)->start->next->content)))
			swap_a(a, b, B_TRUE);
	}
	else
		sort_three_elem_b(a, b);
}

static void			moar_small_lists(t_stacks *stacks, size_t nb_elem)
{
	int				n_to_push;

	if (nb_elem == 5)
	{
		n_to_push = find_n_edge(&(stacks->a), 2, B_TRUE);
		push_n_smallest_b(stacks, 2, n_to_push, B_TRUE);
		sort_three_elem(&(stacks->a), &(stacks->b), B_TRUE);
		if (*((int *)(stacks->b->start->content)) < *((int *)(stacks->b->end->content)))
			swap_b(&(stacks->a), &(stacks->b), B_TRUE);
		push_a(&(stacks->a), &(stacks->b), B_TRUE);
		push_a(&(stacks->a), &(stacks->b), B_TRUE);
	}
	else
	{
		n_to_push = find_n_edge(&(stacks->a), 3, B_TRUE);
		push_n_smallest_b(stacks, 3, n_to_push, B_TRUE);
		sort_three_elem(&(stacks->a), &(stacks->b), B_TRUE);
		sort_three_elem(&(stacks->b), &(stacks->b), B_FALSE);
		push_a(&(stacks->a), &(stacks->b), B_TRUE);
		push_a(&(stacks->a), &(stacks->b), B_TRUE);
		push_a(&(stacks->a), &(stacks->b), B_TRUE);
	}
}

void				handle_small_lists(t_stacks *stacks, size_t nb_elem)
{
	int				n_to_push;

	if (nb_elem == 2)
		swap_a(&(stacks->a), &(stacks->b), B_TRUE);
	else if (nb_elem == 3)
		sort_three_elem(&(stacks->a), &(stacks->b), B_TRUE);
	else if (nb_elem == 4)
	{
		n_to_push = find_n_edge(&(stacks->a), 1, B_TRUE);
		push_n_smallest_b(stacks, 1, n_to_push, B_TRUE);
		sort_three_elem(&(stacks->a), &(stacks->b), B_TRUE);
		push_a(&(stacks->a), &(stacks->b), B_TRUE);
	}
	else
		moar_small_lists(stacks, nb_elem);
}
