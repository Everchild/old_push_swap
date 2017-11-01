/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 00:47:47 by sbrochar          #+#    #+#             */
/*   Updated: 2017/10/31 18:06:05 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static t_instructions	*get_instructions(void)
{
	static t_instructions	ret[NB_INSTR] = {
	{ "sa", &swap_a },
	{ "sb", &swap_b },
	{ "ss", &swap_ab },
	{ "pa", &push_a },
	{ "pb", &push_b },
	{ "ra", &rotate_a },
	{ "rb", &rotate_b },
	{ "rr", &rotate_ab },
	{ "rra", &reverse_rotate_a },
	{ "rrb", &reverse_rotate_b },
	{ "rrr", &reverse_rotate_ab }
	};

	return (ret);
}

static int				check_sort(t_clist **a, t_clist **b)
{
//	ft_printf("%p; %p; I'm checking if the list if sorted!\n", a, b);
	t_node				*cur;

	if ((*b)->start)
		return (PS_KO);
	cur = (*a)->start;
	while (cur != (*a)->end)
	{
		if (*(int *)(cur->content) >= *(int *)(cur->next->content))
			return (PS_KO);
		cur = cur->next;
	}
	return (PS_OK);
}

int						check(t_clist **a)
{
	t_instructions		*all_inst;
	t_clist				*b;
	char				*inst;
	int					i;

	all_inst = get_instructions();
	b = NULL;
	inst = NULL;
	b = create_clist();
	if (*a && b)
	{

	t_node *cura = (*a)->start;
	t_node *curb = b->start;

	ft_putendl("A list:\n");
	while (cura && cura != (*a)->end)
	{
		ft_printf("%d\n", *(int *)(cura->content));
		cura = cura->next;
	}
	if (cura && cura == (*a)->end)
		ft_printf("%d\n\n", *(int *)(cura->content));
	ft_putendl("B list:\n");
	while (curb && curb != b->end)
	{
		ft_printf("%d\n", *(int *)(curb->content));
		curb = curb->next;
	}
	if (curb && curb == b->end)
		ft_printf("%d\n\n", *(int *)(curb->content));
/// start checker
		while (get_next_line(1, &inst))
		{
			i = 0;
			while (i < NB_INSTR)
			{
				if (!ft_strcmp(inst, all_inst[i].str))
					break ;
				i++;
			}
			ft_strdel(&inst);
			if (i == NB_INSTR)
				return (PS_ERROR);
			all_inst[i].instruction(a, &b, B_FALSE);


	cura = (*a)->start;
	curb = b->start;
//	ft_printf("start: %p\n", (*a)->start);
//	ft_printf("end: %p\n", (*a)->end);
	ft_putendl("A list:\n");
	while (cura && cura != (*a)->end)
	{
		ft_printf("%d\n", *(int *)(cura->content));
		cura = cura->next;
	}
	if (cura && cura == (*a)->end)
		ft_printf("%d\n\n", *(int *)(cura->content));
	ft_putendl("B list:\n");
	while (curb && curb != b->end)
	{
		ft_printf("%d\n", *(int *)(curb->content));
		curb = curb->next;
	}
	if (curb && curb == b->end)
		ft_printf("%d\n\n", *(int *)(curb->content));


		}
		return (check_sort(a, &b));
	}
	return (PS_ERROR);
}
