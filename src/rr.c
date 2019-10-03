/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:49:54 by swarner           #+#    #+#             */
/*   Updated: 2019/10/03 17:18:57 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_int_down(const int *original, int *new, size_t len)
{
	size_t 	i;

	i = 0;
	while (i < len - 1)
	{
		new[i + 1] = original[i];
		i++;
	}
}

void		rra(t_tools *tools, int is_visible)
{
	int 	*new_stack;
	size_t	counter;
	size_t	temp;

	if (!tools->size_a || tools->size_a == 1)
		return ;
	counter = tools->size_a - 1;
	temp = tools->stack_a[counter];
	new_stack = create_stack(tools->size_a);
	move_int_down(tools->stack_a, new_stack, tools->size_a);
	new_stack[0] = temp;
	free(tools->stack_a);
	tools->stack_a = new_stack;
	if (is_visible)
		ft_putstr("rra\n");
//	print_stacks(tools);
}

void		rrb(t_tools *tools, int is_visible)
{
	int 	*new_stack;
	size_t	counter;
	size_t	temp;

	if (!tools->size_b || tools->size_b == 1
	|| !tools->stack_b)
		return ;
	counter = tools->size_b - 1;
	temp = tools->stack_b[counter];
	new_stack = create_stack(tools->size_b);
	move_int_down(tools->stack_b, new_stack, tools->size_b);
	new_stack[0] = temp;
	free(tools->stack_b);
	tools->stack_b = new_stack;
	if (is_visible)
		ft_putstr("rrb\n");
//	print_stacks(tools);
}

void		rrr(t_tools *tools, int is_visible)
{
	rra(tools, 0);
	rrb(tools, 0);
	if (is_visible)
		ft_putstr("rrr\n");
}