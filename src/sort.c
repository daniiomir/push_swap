/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:27:10 by swarner           #+#    #+#             */
/*   Updated: 2019/09/24 17:14:00 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

static size_t 	average(size_t a, size_t b)
{
	return ((b - a) / 2);
}

void 		to_stack_b(t_tools *tools)
{
	size_t 	i;
	int		pivot;

	i = 0;
	pivot = tools->stack_a[average(0, tools->size_a) - 1];
	while (tools->size_a > 2)
	{
		if (!tools->size_b)
			operation(pb, tools);
		else if (tools->stack_a[i] > pivot)
			operation(pb, tools);
		else if (tools->stack_a[i] < pivot)
		{
			operation(pb, tools);
			operation(rb, tools);
		}
		else if (tools->stack_a[i] == pivot)
			i++;

	}
	if (!is_sorted(tools))
		operation(sa, tools);
}

void		sort(t_tools *tools)
{
	size_t i;
	size_t j;
	size_t forward;
	size_t back;

	j = 0;
	forward = 0;
	back = 0;
	to_stack_b(tools);
	while (j < tools->count_of_num - 2)
	{
		if (tools->stack_b[0] < tools->stack_a[0])
		{
			operation(pa, tools);
		}
		else if (tools->stack_b[0] > tools->stack_a[tools->size_a - 1])
		{
			operation(pa, tools);
			operation(ra, tools);
		}
		else
		{
			i = 0;
			while (i < tools->size_a - 1)
			{
				if (tools->stack_b[0] > tools->stack_a[i] && tools->stack_b[0] < tools->stack_a[i + 1])
				{
					i++;
					break ;
				}
				else
					i++;
			}
			if (i < average(0, tools->size_a))
			{
				forward = i;
				while (i--)
					operation(ra, tools);
				operation(pa, tools);
				while (forward--)
					operation(rra, tools);
			}
			else
			{
				back = i;
				while (i++ < tools->size_a)
					operation(rra, tools);
				operation(pa, tools);
				while (back++ < tools->size_a)
					operation(ra, tools);
			}
		}
		j++;
	}
}