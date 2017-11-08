/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 01:56:53 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/08 13:25:53 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int					main(int argc, char **argv)
{
	size_t			nb_elem;
	t_clist			*stack;
	t_clist			*b;

	nb_elem = 0;
	stack = NULL;
	b = create_clist();
	if (argc <= 1)
		ft_printf("usage: ./push_swap <nb1> <nb2> <...>\n");
	else
	{
		if (!parsing_args(&nb_elem, &stack, argv + 1) || !b)
			ft_printf("Error\n");
		else
			push_n_swap(&stack, &b, nb_elem);
	}
	return (0);
}
