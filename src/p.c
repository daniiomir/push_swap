/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <swarner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:42:21 by swarner           #+#    #+#             */
/*   Updated: 2019/10/03 17:18:57 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_int(const int *original, int *modyfied, size_t len)
{
	size_t	i;

	if (!modyfied)
		return ;
	i = 0;
	while (i < len)
	{
		modyfied[i] = original[i + 1];
		i++;
	}
}

static void	copy_int2(const int *original, int *modyfied, size_t len)
{
	size_t	i;

	if (!modyfied)
		return ;
	i = 0;
	while (i < len - 1)
	{
		modyfied[i] = original[i];
		i++;
	}
}

static void	move_int(int *stack, size_t len)
{
	size_t i;

	i = len - 1;
	while (i--)
		stack[i + 1] = stack[i];
}

void		pa(t_tools *tools, int is_visible)
{
	int		*stack1;
	int		*stack2;

	if (!tools->size_b)
		return ;
	tools->size_a++;
	tools->size_b--;
	stack1 = create_stack(tools->size_a);
	if (tools->size_b)
		stack2 = create_stack(tools->size_b);
	else
		stack2 = NULL;
	if (tools->size_a - 1 && tools->stack_a)
		copy_int2(tools->stack_a, stack1, tools->size_a);
	copy_int(tools->stack_b, stack2, tools->size_b);
	if (tools->size_a - 1)
		move_int(stack1, tools->size_a);
	stack1[0] = tools->stack_b[0];
	free_stacks(tools);
	tools->stack_a = stack1;
	if (stack2)
		tools->stack_b = stack2;
	if (is_visible)
		ft_putstr("pa\n");
}

void		pb(t_tools *tools, int is_visible)
{
	int		*stack1;
	int		*stack2;

	if (!tools->size_a)
		return ;
	tools->size_a--;
	tools->size_b++;
	stack1 = create_stack(tools->size_a);
	stack2 = create_stack(tools->size_b);
	copy_int(tools->stack_a, stack1, tools->size_a);
	if (tools->size_b - 1 && tools->stack_b)
	{
		copy_int2(tools->stack_b, stack2, tools->size_b);
		move_int(stack2, tools->size_b);
	}
	stack2[0] = tools->stack_a[0];
	free(tools->stack_a);
	if (tools->stack_b)
		free(tools->stack_b);
	tools->stack_a = stack1;
	tools->stack_b = stack2;
	if (is_visible)
		ft_putstr("pb\n");
}
