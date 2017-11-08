/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 00:47:47 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/08 13:19:21 by sbrochar         ###   ########.fr       */
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
		}
		return (check_sort(a, &b));
	}
	return (PS_ERROR);
}
