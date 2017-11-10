/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_in_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 02:23:56 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/10 18:57:02 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void			sort_n_biggest(t_dblist **n_biggest, t_clist **b, size_t n)
{
	t_node			*node;
	t_node			*cur;
	t_node			*number_to_sort;

	number_to_sort = (*b)->start;
	while (n > 0)
	{
		cur = (*n_biggest)->start;
		node = create_node(NULL, 0);
		if (node)
			node->content = (int *)ft_memalloc(sizeof(int));
		if (node && node->content)
		{
			*((int *)(node->content)) = *((int *)(number_to_sort->content));
			while (cur && *((int *)(node->content)) < *((int *)(cur->content)))
				cur = cur->next;
			if (cur)
				dbinsert_node(n_biggest, node, cur);
			else
				dbadd_node_end(n_biggest, node);
			n--;
			number_to_sort = number_to_sort->next;
		}
	}
}

static void			push_node(t_clist **a, t_clist **b, t_bool rb,
					t_node *to_find)
{
	while ((*b)->start != to_find)
	{
		if (rb)
			rotate_b(a, b, B_TRUE);
		else
			reverse_rotate_b(a, b, B_TRUE);
	}
	push_a(a, b, B_TRUE);
}

static void			find_n_biggest(t_clist **a, t_clist **b,
					t_dblist **n_biggest)
{
	t_node			*to_find;
	t_node			*to_push;
	t_node			*save;
	t_bool			rb;

	to_push = (*n_biggest)->start;
	save = (*b)->start;
	while (to_push)
	{
		rb = B_FALSE;
		to_find = save;
		while (*((int *)(to_find->content)) != *((int *)(to_push->content)))
		{
			if (to_find == (*b)->start)
				rb = B_TRUE;
			to_find = to_find->next;
		}
		if (*((int *)(to_find->content)) == *((int *)(save->content)))
			save = save->next;
		push_node(a, b, rb, to_find);
		dbremove_node(n_biggest, to_push);
		to_push = (*n_biggest)->start;
	}
}

void				insert_in_a(t_clist **a, t_clist **b, size_t rest, size_t n)
{
	t_dblist		*n_biggest;

	n_biggest = NULL;
	n_biggest = create_dblist();
	if (n_biggest)
	{
		sort_n_biggest(&n_biggest, b, rest);
		find_n_biggest(a, b, &n_biggest);
		while ((*b)->nb_nodes)
		{
			sort_n_biggest(&n_biggest, b, n);
			find_n_biggest(a, b, &n_biggest);
		}
	}
	free_dblist(&n_biggest);
}
