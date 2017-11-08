/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_on_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:30:04 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/08 18:25:53 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static t_bool		choose_rotating_way(t_clist **list, int n_smallest)
{
	size_t			check_r;
	size_t			check_rr;
	t_node			*cur;

	check_r = 0;
	check_rr = 0;
	cur = (*list)->start;
	while (*((int *)(cur->content)) > n_smallest)
	{
		cur = cur->next;
		check_r++;
	}
	cur = (*list)->start;
	while (*((int *)(cur->content)) > n_smallest)
	{
		cur = cur->prev;
		check_rr++;
	}
	return (check_r < check_rr);
}

void				push_n_smallest_b(t_stacks *stacks, size_t n, int n_smallest, t_bool first)
{
	size_t			i;
	t_bool			ra;

	i = 0;
	while (i < n)
	{
		if (first)
			ra = 1;
		else
			ra = choose_rotating_way(&(stacks->a), n_smallest);
		while (*((int *)(stacks->a->start->content)) > n_smallest)
		{
			if (ra)
				rotate_a(&(stacks->a), &(stacks->b), B_TRUE);
			else
				reverse_rotate_a(&(stacks->a), &(stacks->b), B_TRUE);
		}
		push_b(&(stacks->a), &(stacks->b), B_TRUE);
		i++;
	}
}
