/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <swarner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:39:50 by swarner           #+#    #+#             */
/*   Updated: 2019/09/03 21:39:50 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *tools)
{
	int temp;

	if ((!tools->stack_a[0] && !tools->stack_a[1])
	|| !tools->stack_a[1])
		return ;
	temp = tools->stack_a[0];
	tools->stack_a[0] = tools->stack_a[1];
	tools->stack_a[1] = temp;
}

void	sb(t_stack *tools)
{
	int temp;

	if ((!tools->stack_b[0] && !tools->stack_b[1])
		|| !tools->stack_b[1])
		return ;
	temp = tools->stack_b[0];
	tools->stack_b[0] = tools->stack_b[1];
	tools->stack_b[1] = temp;
}

void	ss(t_stack *tools)
{
	sa(tools);
	sb(tools);
}