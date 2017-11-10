/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 01:56:53 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/10 19:27:24 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int					main(int argc, char **argv)
{
	size_t			nb_elem;
	t_stacks		stacks;
//	t_clist			*stack;
//	t_clist			*b;

	nb_elem = 0;
	stacks.a = NULL;
	stacks.b = create_clist();
	if (argc <= 1)
		ft_printf("usage: ./push_swap <nb1> <nb2> <...>\n");
	else
	{
		if (!parsing_args(&nb_elem, &(stacks.a), argv + 1) || !(stacks.b))
			ft_printf("Error\n");
		else
			push_n_swap(&stacks, nb_elem);
	}
	while (1)
	{}
	return (0);
}
