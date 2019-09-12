/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <swarner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:42:31 by swarner           #+#    #+#             */
/*   Updated: 2019/09/12 17:03:49 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_int_up(const int *original, int *new, size_t len)
{
	size_t 	i;

	i = len;
	while (--i)
	{
		new[i - 1] = original[i];
	}
}

void		ra(t_tools *tools)
{
	int 	*new_stack;
	size_t	counter;
	size_t	temp;

	if (!tools->size_a || tools->size_a == 1)
		return ;
	new_stack = (int *)malloc(sizeof(int) * tools->size_a);
	temp = tools->stack_a[0];
	counter = tools->size_a - 1;
	move_int_up(tools->stack_a, new_stack, tools->size_a);
	new_stack[counter] = temp;
	free(tools->stack_a);
	tools->stack_a = new_stack;
}

void		rb(t_tools *tools)
{
	int 	*new_stack;
	size_t	counter;
	size_t	temp;

	if (!tools->size_b || tools->size_b == 1)
		return ;
	new_stack = (int *)malloc(sizeof(int) * tools->size_a);
	temp = tools->stack_b[0];
	counter = tools->size_b - 1;
	move_int_up(tools->stack_b, new_stack, tools->size_b);
	new_stack[counter] = temp;
	free(tools->stack_b);
	tools->stack_b = new_stack;
}

void		rr(t_tools *tools)
{
	ra(tools);
	rb(tools);
}