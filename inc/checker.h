/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 13:13:02 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/03 02:28:39 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <libft.h>

# define NB_INSTR 11
# define PS_OK 1
# define PS_KO 2
# define PS_ERROR 3

typedef struct		s_instructions
{
	char			*str;
	void			(*instruction)(t_clist **, t_clist **, t_bool);
}					t_instructions;

t_bool				parsing_args(size_t *nb_elem, t_clist **stack, char **args);
void				swap_a(t_clist **a, t_clist **b, t_bool sort);
void				swap_b(t_clist **a, t_clist **b, t_bool sort);
void				swap_ab(t_clist **a, t_clist **b, t_bool sort);
void				push_a(t_clist **a, t_clist **b, t_bool sort);
void				push_b(t_clist **a, t_clist **b, t_bool sort);
void				rotate_a(t_clist **a, t_clist **b, t_bool sort);
void				rotate_b(t_clist **a, t_clist **b, t_bool sort);
void				rotate_ab(t_clist **a, t_clist **b, t_bool sort);
void				reverse_rotate_a(t_clist **a, t_clist **b, t_bool sort);
void				reverse_rotate_b(t_clist **a, t_clist **b, t_bool sort);
void				reverse_rotate_ab(t_clist **a, t_clist **b, t_bool sort);

int					check(t_clist **a);

void				push_n_swap(t_clist **a, t_clist **b, size_t nb_elem);
void				insert_in_a(t_clist **a, t_clist **b, size_t rest, size_t n);

#endif
