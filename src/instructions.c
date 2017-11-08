/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 00:11:06 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/08 13:25:20 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void				swap_a(t_clist **a, t_clist **b, t_bool sort)
{
	if (sort)
		ft_printf("sa\n");
	if (a && *a && (*a)->nb_nodes > 1)
		swap_nodes(&(*a)->start, &(*a)->start->next);
	b = (t_clist **)b;
}

void				swap_b(t_clist **a, t_clist **b, t_bool sort)
{
	if (sort)
		ft_printf("sb\n");
	if (b && *b && (*b)->nb_nodes > 1)
		swap_nodes(&(*b)->start, &(*b)->start->next);
	a = (t_clist **)a;
}

void				swap_ab(t_clist **a, t_clist **b, t_bool sort)
{
	if (sort)
		ft_printf("ss\n");
	swap_a(a, b, B_FALSE);
	swap_b(a, b, B_FALSE);
}

void				push_a(t_clist **a, t_clist **b, t_bool sort)
{
	t_node			*new;

	if (sort)
		ft_printf("pa\n");
	if (b && *b && (*b)->nb_nodes >= 1)
	{
		new = create_node(NULL, 0);
		new->content = (int *)ft_memalloc(sizeof(int));
		*(int *)(new->content) = *(int *)((*b)->start->content);
		cadd_node_start(a, new);
		cremove_node(b, (*b)->start);
	}
}

void				push_b(t_clist **a, t_clist **b, t_bool sort)
{
	t_node			*new;

	if (sort)
		ft_printf("pb\n");
	if (a && *a && (*a)->nb_nodes >= 1)
	{
		new = create_node(NULL, 0);
		new->content = (int *)ft_memalloc(sizeof(int));
		*(int *)(new->content) = *(int *)((*a)->start->content);
		cadd_node_start(b, new);
		cremove_node(a, (*a)->start);
	}
}

void				rotate_a(t_clist **a, t_clist **b, t_bool sort)
{
	if (sort)
		ft_printf("ra\n");
	if (a && *a && (*a)->nb_nodes > 1)
	{
		(*a)->start = (*a)->start->next;
		(*a)->end = (*a)->end->next;
	}
	b = (t_clist **)b;
}

void				rotate_b(t_clist **a, t_clist **b, t_bool sort)
{
	if (sort)
		ft_printf("rb\n");
	if (b && *b && (*b)->nb_nodes > 1)
	{
		(*b)->start = (*b)->start->next;
		(*b)->end = (*b)->end->next;
	}
	a = (t_clist **)a;
}

void				rotate_ab(t_clist **a, t_clist **b, t_bool sort)
{
	if (sort)
		ft_printf("rr\n");
	rotate_a(a, b, B_FALSE);
	rotate_b(a, b, B_FALSE);
}

void				reverse_rotate_a(t_clist **a, t_clist **b, t_bool sort)
{
	if (sort)
		ft_printf("rra\n");
	if (a && *a && (*a)->nb_nodes > 1)
	{
		(*a)->start = (*a)->start->prev;
		(*a)->end = (*a)->end->prev;
	}
	b = (t_clist **)b;
}

void				reverse_rotate_b(t_clist **a, t_clist **b, t_bool sort)
{
	if (sort)
		ft_printf("rrb\n");
	if (b && *b && (*b)->nb_nodes > 1)
	{
		(*b)->start = (*b)->start->prev;
		(*b)->end = (*b)->end->prev;
	}
	a = (t_clist **)a;
}

void				reverse_rotate_ab(t_clist **a, t_clist **b, t_bool sort)
{
	if (sort)
		ft_printf("rrr\n");
	reverse_rotate_a(a, b, B_FALSE);
	reverse_rotate_b(a, b, B_FALSE);
}
