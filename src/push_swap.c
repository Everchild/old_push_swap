/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 01:56:53 by sbrochar          #+#    #+#             */
/*   Updated: 2017/10/19 05:57:32 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int					main(int argc, char **argv)
{
	size_t			nb_elem;
	t_clist			*stack;

	nb_elem = 0;
	stack = NULL;
	if (argc <= 1)
		ft_printf("usage: ./push_swap <nb1> <nb2> <...>\n");
	else
	{
		if (!parsing_args(&nb_elem, &stack, argv + 1))
			ft_printf("Error\n");
		else
		{
			ft_printf("push & swap\n");
		}
	}
	return (0);
}
