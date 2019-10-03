/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:24:53 by swarner           #+#    #+#             */
/*   Updated: 2019/10/03 17:18:57 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

static void	find_operations(t_tools *tools, char *op)
{
	if (ft_strequ(op, "sa"))
		operation(sa, tools);
	else if (ft_strequ(op, "sb"))
		operation(sb, tools);
	else if (ft_strequ(op, "ss"))
		operation(ss, tools);
	else if (ft_strequ(op, "pa"))
		operation(pa, tools);
	else if (ft_strequ(op, "pb"))
		operation(pb, tools);
	else if (ft_strequ(op, "ra"))
		operation(ra, tools);
	else if (ft_strequ(op, "rb"))
		operation(rb, tools);
	else if (ft_strequ(op, "rr"))
		operation(rr, tools);
	else if (ft_strequ(op, "rra"))
		operation(rra, tools);
	else if (ft_strequ(op, "rrb"))
		operation(rrb, tools);
	else if (ft_strequ(op, "rrr"))
		operation(rrr, tools);
	else
		tools->error = 1;
}

static void	checker(t_tools *tools)
{
	char *operation;

	while (get_next_line(0, &operation))
	{
		find_operations(tools, operation);
		if (tools->error)
			return ;
		free(operation);
	}
}

static void	into_checker(t_tools *tools)
{
	if (!tools->error && !find_duplicates(tools))
	{
		checker(tools);
		if (tools->error)
			ft_error();
		else if (is_sorted(tools) && !tools->size_b)
			ft_putstr("\x1b[32mOK\n");
		else
			ft_putstr("\x1b[31mKO\n");
	}
	else
		ft_error();
}

int			main(int argc, char **argv)
{
	int			i;
	size_t		counter;
	t_tools		tools;

	if (argc > 1)
	{
		i = 1;
		counter = 0;
		tools.debug = 0;
		init_valies(&tools);
		len_for_stack(argc, argv, &tools);
		tools.stack_a = create_stack(tools.count_of_num);
		tools.stack_b = create_stack(tools.count_of_num);
		while (argc > i)
			handle_arg(argv[i++], &tools, &counter);
		into_checker(&tools);
		free(tools.stack_a);
		if (tools.stack_b)
			free(tools.stack_b);
	}
}
