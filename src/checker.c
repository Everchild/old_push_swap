/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 13:13:24 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/08 13:17:07 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int					main(int argc, char **argv)
{
	size_t			nb_elem;
	t_clist			*stack;
	int				result;

	nb_elem = 0;
	stack = NULL;
	if (argc <= 1)
		ft_printf("usage: ./checker <nb1> <nb2> <...>\n");
	else
	{
		if (!parsing_args(&nb_elem, &stack, argv + 1))
			ft_printf("Error\n");
		else
		{
			result = check(&stack);
			if (result == PS_OK)
				ft_printf("OK\n");
			else if (result == PS_KO)
				ft_printf("KO\n");
			else if (result == PS_ERROR)
				ft_printf("Error\n");
		}
	}
	return (0);
}
