/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 21:03:59 by swarner           #+#    #+#             */
/*   Updated: 2019/10/03 21:10:44 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

int		find_min_index(const int *stack, int len)
{
	int		i;
	int		tmp;
	int		index;

	if (len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < len)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int		find_max_index(const int *stack, int len)
{
	int		i;
	int		tmp;
	int		index;

	if (len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < len)
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int		find_min_elem(const int *stack, int stack_len)
{
	register int i;
	register int tmp;
	register int index;

	if (stack_len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < stack_len)
	{
		if (tmp > stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int		find_max_elem(const int *stack, int stack_len)
{
	int i;
	int tmp;
	int index;

	if (stack_len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = stack[i];
	while (i < stack_len)
	{
		if (tmp < stack[i])
		{
			tmp = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	place_smallest_first_a(t_tools *tools)
{
	size_t	min_index;

	min_index = find_min_index(tools->stack_a, tools->size_a);
	if (min_index <= tools->size_a / 2)
		while (min_index--)
			operation(ra, tools);
	else
		while ((tools->size_a - min_index) > 0)
		{
			operation(rra, tools);
			min_index++;
		}
}
