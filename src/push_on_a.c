/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_on_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:30:04 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/08 13:15:08 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static t_bool		choose_rotating_way(t_clist **list, int n_biggest)
{
	size_t			check_r;
	size_t			check_rr;
	t_node			*cur;

	check_r = 0;
	check_rr = 0;
	cur = (*list)->start;
	while (*((int *)(cur->content)) < n_biggest)
	{
		cur = cur->next;
		check_r++;
	}
	cur = (*list)->start;
	while (*((int *)(cur->content)) < n_biggest)
	{
		cur = cur->prev;
		check_rr++;
	}
	return (check_r < check_rr);
}

void				push_n_biggest_a(t_clist **a, t_clist **b, size_t n,
					int n_biggest)
{
	size_t			i;
	t_bool			rb;

	i = 0;
	while (i < n)
	{
		rb = choose_rotating_way(b, n_biggest);
		while (*((int *)((*b)->start->content)) < n_biggest)
		{
			if (rb)
				rotate_b(a, b, B_TRUE);
			else
				reverse_rotate_b(a, b, B_TRUE);
		}
		push_a(a, b, B_TRUE);
		i++;
	}
}
