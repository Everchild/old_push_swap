/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 13:34:19 by sbrochar          #+#    #+#             */
/*   Updated: 2017/10/19 01:02:53 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

t_bool				check_errors(char *args)
{
//	ft_printf("I am checking for errors in [%s]!\n", args);
	int				i;

	i = 0;
	while (args && args[i])
	{
		if (!ft_isdigit(args[i])
				&& (args[i] != '-' && args[i] != ' ' && args[i] != '+'))
//		{
//			ft_printf("error 1\n");
			return (B_FALSE);
//		}
		if ((args[i] == '-' || args[i] == '+')
				&& ((i > 0 && args[i - 1] != ' ') || !ft_isdigit(args[i + 1])))
//		{
//			ft_printf("error 2\n");
			return (B_FALSE);
//		}
		i++;
	}
	return (B_TRUE);
}

static t_bool		create_stack(size_t *nb_elem, t_clist **stack, char **args)
{
//	ft_printf("I am creating the first stack!\n");
	t_node			*node;
	t_node			*cur;

	node = NULL;
	*stack = create_clist();
	while (args && args[*nb_elem])
	{
		node = create_node(NULL, 0);
		node->content = (int *)ft_memalloc(sizeof(int));

//		ft_printf("arg #%d: [%s]\n", *nb_elem, args[*nb_elem]);
		if (!ft_batoi((int *)(node->content), args[*nb_elem]))
//		{
//			ft_printf("bla\n");
			return (B_FALSE);
//		}
//		ft_printf("arg #%d: [%s]\n", *nb_elem, args[*nb_elem]);
		cadd_node_end(stack, node);
		cur = (*stack)->start;
		while (cur != (*stack)->end)
		{
//			ft_printf("new node: %d | cur node: %d\n", *((int *)(node->content)), *((int *)(cur->content)));
			if (*((int *)(node->content)) == *((int *)(cur->content)))
//			{
//				ft_printf("truc\n");
				return (B_FALSE);
//			}
			cur = cur->next;
		}
		(*nb_elem)++;
	}
	return (B_TRUE);
}

t_bool				parsing_args(size_t *nb_elem, t_clist **stack, char **args)
{
//	ft_printf("I am parsing args!\n");
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
