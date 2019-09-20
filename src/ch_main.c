/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:24:53 by swarner           #+#    #+#             */
/*   Updated: 2019/09/20 13:14:33 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

static void	operations(t_tools *tools, char *operation)
{
	if (ft_strequ(operation, "sa"))
		sa(tools, 0);
	else if (ft_strequ(operation, "sb"))
		sb(tools, 0);
	else if (ft_strequ(operation, "ss"))
		ss(tools, 0);
	else if (ft_strequ(operation, "pa"))
		pa(tools, 0);
	else if (ft_strequ(operation, "pb"))
		pb(tools, 0);
	else if (ft_strequ(operation, "ra"))
		ra(tools, 0);
	else if (ft_strequ(operation, "rb"))
		rb(tools, 0);
	else if (ft_strequ(operation, "rr"))
		rr(tools, 0);
	else if (ft_strequ(operation, "rra"))
		rra(tools, 0);
	else if (ft_strequ(operation, "rrb"))
		rrb(tools, 0);
	else if (ft_strequ(operation, "rrr"))
		rrr(tools, 0);
	else
		tools->error = 1;
}

static void	checker(t_tools *tools)
{
	char *operation;

	while (get_next_line(0, &operation))
	{
		operations(tools, operation);
		if (tools->error)
			return ;
		free(operation);
	}
}

int			main(int argc, char **argv)
{
	int		    i;
	size_t 		counter;
	t_tools	    tools;

	if (argc > 1)
	{
		i = 1;
		counter = 0;
		init_valies(&tools);
		len_for_stack(argc, argv, &tools);
		tools.stack_a = (int *)malloc(sizeof(int) * tools.count_of_num);
		tools.stack_b = (int *)malloc(sizeof(int) * tools.count_of_num);
		while (argc > i)
			handle_arg(argv[i++], &tools, &counter);
		if (!tools.error && !find_duplicates(&tools))
		{
			checker(&tools);
			if (tools.error)
				ft_error();
			else if (is_sorted(&tools) && !tools.size_b)
				ft_putstr("OK\n");
			else
				ft_putstr("KO\n");
		}
		else
			ft_error();
		free(tools.stack_a);
		free(tools.stack_b);
	}
}

