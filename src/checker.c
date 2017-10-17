/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 13:13:24 by sbrochar          #+#    #+#             */
/*   Updated: 2017/10/17 23:03:15 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int					main(int argc, char **argv)
{
	ft_printf("I am a checker!\n");
	size_t			nb_elem;
	t_clist			*stack;

	nb_elem = 0;
	stack = NULL;
	int d = 0;
	while (argv[d])
	{
		ft_printf("arg #%d: [%s]\n", d, argv[d]);
		d++;
	}
	if (argc <= 1)
		ft_printf("usage: ./checker <nb1> <nb2> <...>\n");
	else
	{
		if (!parsing_args(&nb_elem, &stack, argv + 1))
			ft_printf("Error\n");
		else
		{
			t_node *cur = stack->start;
			int i = 0;
			while (cur != stack->end)
			{
				ft_printf("elem #%d: %d\n", i, *((int *)(cur->content)));
				i++;
				cur = cur->next;
			}
			ft_printf("elem #%d: %d\n", i, *((int*)(cur->content)));
			ft_printf("Let's check!\n");
		}
	}
	return (0);
}
