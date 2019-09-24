/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:24:42 by swarner           #+#    #+#             */
/*   Updated: 2019/09/24 17:03:50 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

int		main(int argc, char **argv)
{
	int		    i;
	size_t 		counter;
	t_tools	    tools;

	if (argc > 1)
	{
		i = 1;
		counter = 0;
		init_valies(&tools);
		tools.debug = 1;
		tools.is_visible = 1;
		len_for_stack(argc, argv, &tools);
		tools.stack_a = create_stack(tools.count_of_num);
		tools.stack_b = create_stack(tools.count_of_num);
		while (argc > i)
			handle_arg(argv[i++], &tools, &counter);
		if (find_duplicates(&tools))
			tools.error = 1;
//		 print_stacks(&tools);
		if (!is_sorted(&tools) && !tools.error)
			algorithm(&tools);
		free(tools.stack_a);
		if (tools.stack_b)
			free(tools.stack_b);
	}
	else
		ft_error();
}
