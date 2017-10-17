/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 00:11:06 by sbrochar          #+#    #+#             */
/*   Updated: 2017/10/18 01:57:16 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void				swap_a(t_clist **a, t_clist **b)
{
	ft_printf("%p; %p; ", a, b);
	ft_printf("I am swapping the first two elements of a!\n");
}

void				swap_b(t_clist **a, t_clist **b)
{
	ft_printf("%p; %p; ", a, b);
	ft_printf("I am swapping the first two elements of b!\n");
}

void				swap_ab(t_clist **a, t_clist **b)
{
	ft_printf("%p; %p; ", a, b);
	ft_printf("I am swapping the first two elements of a and b!\n");
}

void				push_a(t_clist **a, t_clist **b)
{
	ft_printf("%p; %p; ", a, b);
	ft_printf("I am pushing the first element of b and putting it on a!\n");
}

void				push_b(t_clist **a, t_clist **b)
{
	ft_printf("%p; %p; ", a, b);
	ft_printf("I am pushing the first element of a and putting it on b!\n");
}

void				rotate_a(t_clist **a, t_clist **b)
{
	ft_printf("%p; %p; ", a, b);
	ft_printf("I am rotating a up!\n");
}

void				rotate_b(t_clist **a, t_clist **b)
{
	ft_printf("%p; %p; ", a, b);
	ft_printf("I am rotating b up!\n");
}

void				rotate_ab(t_clist **a, t_clist **b)
{
	ft_printf("%p; %p; ", a, b);
	ft_printf("I am rotating a and b up!\n");
}

void				reverse_rotate_a(t_clist **a, t_clist **b)
{
	ft_printf("%p; %p; ", a, b);
	ft_printf("I am rotating a down!\n");
}

void				reverse_rotate_b(t_clist **a, t_clist **b)
{
	ft_printf("%p; %p; ", a, b);
	ft_printf("I am rotating b down!\n");
}

void				reverse_rotate_ab(t_clist **a, t_clist **b)
{
	ft_printf("%p; %p; ", a, b);
	ft_printf("I am rotating a and b down!\n");
}
