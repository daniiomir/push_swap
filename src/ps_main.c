/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:24:42 by swarner           #+#    #+#             */
/*   Updated: 2019/09/20 13:24:41 by swarner          ###   ########.fr       */
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
		len_for_stack(argc, argv, &tools);
		tools.stack_a = (int *)malloc(sizeof(int) * tools.size_a);
		tools.stack_b = (int *)malloc(sizeof(int) * tools.count_of_num);
		while (argc > i)
			handle_arg(argv[i++], &tools, &counter);
		if (find_duplicates(&tools))
			ft_error();
		if (!is_sorted(&tools))
			algorithm(&tools);
//		print_stacks(&tools);
		free(tools.stack_a);
		free(tools.stack_b);
	}
	else
		ft_error();
}
