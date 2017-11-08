/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:10:15 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/08 18:23:59 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>


void				push_n_swap(t_stacks *stacks, size_t nb_elem)
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
		}
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
}
