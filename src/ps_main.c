/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:24:42 by swarner           #+#    #+#             */
/*   Updated: 2019/10/03 22:25:35 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

static void	into_push_swap(t_tools *tools)
{
	if (find_duplicates(tools))
		tools->error = 1;
	if (!is_sorted(tools) && !tools->error)
		algorithm(tools);
	if (tools->debug)
	{
		ft_putstr("Count of opertions: ");
		ft_putnbr(tools->op_count);
		ft_putstr("\n");
	}
}

int			main(int argc, char **argv)
{
	int			i;
	int			for_arg;
	size_t		counter;
	t_tools		tools;

	if (argc > 1)
	{
		i = 1;
		counter = 0;
		init_valies(&tools);
		for_arg = parse_options(argv[1], argv[2], &tools);
		i = i + for_arg;
		tools.is_visible = 1;
		len_for_stack(argc, argv, &tools);
		tools.stack_a = create_stack(tools.count_of_num);
		tools.stack_b = create_stack(tools.count_of_num);
		while (argc > i)
			handle_arg(argv[i++], &tools, &counter);
		into_push_swap(&tools);
		free(tools.stack_a);
		if (tools.stack_b)
			free(tools.stack_b);
	}
	else
		ft_error();
}
