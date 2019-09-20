/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <swarner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:46:46 by dan               #+#    #+#             */
/*   Updated: 2019/09/19 20:50:57 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

static void	algorithm_3(t_tools *tools)
{
	if (tools->stack_a[0] < tools->stack_a[1]
	&& tools->stack_a[1] > tools->stack_a[2]
	&& tools->stack_a[0] < tools->stack_a[2])
	{
		sa(tools, 1);
		ra(tools, 1);
	}
	else if (tools->stack_a[0] < tools->stack_a[1]
	&& tools->stack_a[1] > tools->stack_a[2]
	&& tools->stack_a[0] > tools->stack_a[2])
		rra(tools, 1);
	else if (tools->stack_a[0] > tools->stack_a[1]
	&& tools->stack_a[1] < tools->stack_a[2]
	&& tools->stack_a[0] < tools->stack_a[2])
		sa(tools, 1);
	else if (tools->stack_a[0] > tools->stack_a[1]
	&& tools->stack_a[1] < tools->stack_a[2]
	&& tools->stack_a[0] > tools->stack_a[2])
		ra(tools, 1);
	else if (tools->stack_a[0] > tools->stack_a[1]
	&& tools->stack_a[1] > tools->stack_a[2]
	&& tools->stack_a[0] > tools->stack_a[2])
	{
		sa(tools, 1);
		rra(tools, 1);
	}
}

static void	algorithm_4(t_tools *tools)
{
	size_t	i;
	size_t 	min;

	i = 0;
	min = 0;
	while (i < tools->count_of_num - 1)
	{
		if (tools->stack_a[i] < tools->stack_a[min])
			min = i;
		i++;
	}
	while (min)
	{
		ra(tools, 1);
		min--;
	}
	pb(tools, 1);
	algorithm_3(tools);
	pa(tools, 1);
}

static void	algorithm_5(t_tools *tools)
{
	size_t	i;
	size_t 	min;

	i = 0;
	min = 0;
	while (i < tools->count_of_num - 1)
	{
		if (tools->stack_a[i] < tools->stack_a[min])
			min = i;
		i++;
	}
	while (min)
	{
		ra(tools, 1);
		min--;
	}
	pb(tools, 1);
	algorithm_4(tools);
	pa(tools, 1);
}

void 		algorithm(t_tools *tools)
{
	if (tools->count_of_num == 2)
		sa(tools, 1);
	else if (tools->count_of_num == 3)
		algorithm_3(tools);
	else if (tools->count_of_num == 4)
		algorithm_4(tools);
	else if (tools->count_of_num == 5)
		algorithm_5(tools);
}