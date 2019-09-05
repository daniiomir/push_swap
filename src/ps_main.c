/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:24:42 by swarner           #+#    #+#             */
/*   Updated: 2019/09/04 18:20:46 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	int		    i;
	t_tools	    tools;
	t_dlist_num	*stack_a;
	t_dlist_num	*stack_b;

	if (argc > 1)
	{
		i = 1;
		len_for_stack(argc, argv, &tools);
		stack_a = ft_dlist_new_num(0);
		stack_b = ft_dlist_new_num(0);
		while (argc > i)
		{
			handle_arg(argv[i], &stack_a);
			i++;
		}
		ft_dlisthead_num_del(&stack_a);
		if (find_duplicates(&stack_a))
			ft_error();
		free(stack_a);
		free(stack_b);
	}
	else
		ft_error();
}
