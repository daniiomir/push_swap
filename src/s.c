/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <swarner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:39:50 by swarner           #+#    #+#             */
/*   Updated: 2019/09/11 18:06:11 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_tools *tools, int is_visible)
{
	int temp;

	if (!tools->size_a || tools->size_a == 1)
		return ;
	temp = tools->stack_a[0];
	tools->stack_a[0] = tools->stack_a[1];
	tools->stack_a[1] = temp;
	if (is_visible)
		ft_putstr("sa\n");
//	print_stacks(tools);
}

void	sb(t_tools *tools, int is_visible)
{
	int temp;

	if (!tools->size_b || tools->size_b == 1)
		return ;
	temp = tools->stack_b[0];
	tools->stack_b[0] = tools->stack_b[1];
	tools->stack_b[1] = temp;
	if (is_visible)
		ft_putstr("sb\n");
//	print_stacks(tools);
}

void	ss(t_tools *tools, int is_visible)
{
	sa(tools, 0);
	sb(tools, 0);
	if (is_visible)
		ft_putstr("ss\n");
}