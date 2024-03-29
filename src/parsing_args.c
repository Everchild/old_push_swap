/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 13:34:19 by sbrochar          #+#    #+#             */
/*   Updated: 2017/11/08 13:17:51 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

t_bool				check_errors(char *args)
{
	int				i;

	i = 0;
	while (args && args[i])
	{
		if (!ft_isdigit(args[i])
				&& (args[i] != '-' && args[i] != ' ' && args[i] != '+'))
			return (B_FALSE);
		if ((args[i] == '-' || args[i] == '+')
				&& ((i > 0 && args[i - 1] != ' ') || !ft_isdigit(args[i + 1])))
			return (B_FALSE);
		i++;
	}
	return (B_TRUE);
}

static t_bool		create_stack(size_t *nb_elem, t_clist **stack, char **args)
{
	t_node			*node;
	t_node			*cur;

	node = NULL;
	*stack = create_clist();
	while (args && args[*nb_elem])
	{
		node = create_node(NULL, 0);
		node->content = (int *)ft_memalloc(sizeof(int));
		if (!ft_batoi((int *)(node->content), args[*nb_elem]))
			return (B_FALSE);
		cadd_node_end(stack, node);
		cur = (*stack)->start;
		while (cur != (*stack)->end)
		{
			if (*((int *)(node->content)) == *((int *)(cur->content)))
				return (B_FALSE);
			cur = cur->next;
		}
		(*nb_elem)++;
	}
	return (B_TRUE);
}

t_bool				parsing_args(size_t *nb_elem, t_clist **stack, char **args)
{
	char			*str;
	char			*tmp;

	tmp = ft_tabtostr(args);
	str = ft_strtrimall(tmp);
	ft_strdel(&tmp);
	if (!check_errors(str))
		return (B_FALSE);
	args = ft_strsplit(str, ' ');
	ft_strdel(&str);
	return (create_stack(nb_elem, stack, args));
}
