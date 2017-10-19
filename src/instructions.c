/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 00:11:06 by sbrochar          #+#    #+#             */
/*   Updated: 2017/10/19 01:13:02 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void				swap_a(t_clist **a, t_clist **b)
{
	if (a && *a && (*a)->nb_nodes > 1)
		swap_nodes(&(*a)->start, &(*a)->start->next);
	b = (t_clist **)b;
}

void				swap_b(t_clist **a, t_clist **b)
{
	if (b && *b && (*b)->nb_nodes > 1)
		swap_nodes(&(*b)->start, &(*b)->start->next);
	a = (t_clist **)a;
}

void				swap_ab(t_clist **a, t_clist **b)
{
	swap_a(a, b);
	swap_b(a, b);
}

/*static void				testcremove_node(t_clist **list, t_node *node)
{
//	ft_printf("addr list->start: %p\n", (*list)->start);
//	ft_printf("addr node->prev: %p\n", node->prev);
//	ft_printf("addr node to remove: %p\n", node);
//	ft_printf("addr node->next: %p\n", node->next);
//	ft_printf("addr list->end: %p\n", (*list)->end);
	if (list && *list && node)
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		if (node == (*list)->start)
			(*list)->start = node->next;
		if (node == (*list)->end)
			(*list)->end = node->prev;
		ft_memdel((void **)&(node->content));
		ft_memdel((void **)&node);
		if ((*list)->nb_nodes == 1)
		{
			(*list)->start = NULL;
			(*list)->end = NULL;
		}
		(*list)->nb_nodes -= 1;
	}
//	ft_printf("addr list->start: %p\n", (*list)->start);
//	ft_printf("addr node removed: %p\n", node);
//	ft_printf("addr list->end: %p\n", (*list)->end);
}*/

void				push_a(t_clist **a, t_clist **b)
{
	t_node			*new;

	if (b && *b && (*b)->nb_nodes >= 1)
	{
		new = create_node(NULL, 0);
		new->content = (int *)ft_memalloc(sizeof(int));
		*(int *)(new->content) = *(int *)((*b)->start->content);
		cadd_node_start(a, new);
		cremove_node(b, (*b)->start);
	}
}

void				push_b(t_clist **a, t_clist **b)
{
	t_node			*new;

	if (a && *a && (*a)->nb_nodes >= 1)
	{
//		ft_printf("test1\n");
		new = create_node(NULL, 0);
//		ft_printf("node to add: %p\n", new);
		new->content = (int *)ft_memalloc(sizeof(int));
		*(int *)(new->content) = *(int *)((*a)->start->content);
//		ft_printf("list->start before adding: %p\n", (*a)->start);
		cadd_node_start(b, new);
//		ft_printf("list->start after adding: %p\n", (*a)->start);
		cremove_node(a, (*a)->start);
//		ft_printf("test6\n");
	}
}

void				rotate_a(t_clist **a, t_clist **b)
{
	if (a && *a && (*a)->nb_nodes > 1)
	{
		(*a)->start = (*a)->start->next;
		//		ft_printf("a->end->next: %d\n", *(int *)((*a)->end->next->content));
		(*a)->end = (*a)->end->next;
	}
	b = (t_clist **)b;
}

void				rotate_b(t_clist **a, t_clist **b)
{
	if (b && *b && (*b)->nb_nodes > 1)
	{
		(*b)->start = (*b)->start->next;
		(*b)->end = (*b)->end->next;
	}
	a = (t_clist **)a;
}

void				rotate_ab(t_clist **a, t_clist **b)
{
	rotate_a(a, b);
	rotate_b(a, b);
}

void				reverse_rotate_a(t_clist **a, t_clist **b)
{
	if (a && *a && (*a)->nb_nodes > 1)
	{
		(*a)->start = (*a)->start->prev;
		(*a)->end = (*a)->end->prev;
	}
	b = (t_clist **)b;
}

void				reverse_rotate_b(t_clist **a, t_clist **b)
{
	if (b && *b && (*b)->nb_nodes > 1)
	{
		(*b)->start = (*b)->start->prev;
		(*b)->end = (*b)->end->prev;
	}
	a = (t_clist **)a;
}

void				reverse_rotate_ab(t_clist **a, t_clist **b)
{
	reverse_rotate_a(a, b);
	reverse_rotate_b(a, b);
}
