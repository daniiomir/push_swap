/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 23:20:18 by swarner           #+#    #+#             */
/*   Updated: 2019/10/03 23:20:19 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			free_stacks(t_tools *tools)
{
	if (tools->stack_a)
		free(tools->stack_a);
	if (tools->size_b)
		free(tools->stack_b);
}

int				*create_stack(size_t size)
{
	int *stack;

	stack = (int *)malloc(sizeof(int) * size);
	return (stack);
}

size_t			is_sorted(t_tools *tools)
{
	size_t	i;

	i = 0;
	while (i < tools->size_a - 1)
	{
		if (tools->stack_a[i] > tools->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static size_t	find_duplicates_helper(t_tools *tools, size_t i)
{
	size_t	j;
	size_t	count;
	size_t	is_dup;

	j = 0;
	count = 0;
	is_dup = 0;
	while (j < tools->count_of_num)
	{
		if (tools->stack_a[i] == tools->stack_a[j] && !count && !is_dup)
		{
			if (j < tools->count_of_num)
				j++;
			else
				break ;
			count++;
		}
		if (tools->stack_a[i] == tools->stack_a[j])
			return (1);
		count == 0 ? j++ : (count-- && is_dup++);
	}
	return (0);
}

size_t			find_duplicates(t_tools *tools)
{
	size_t	i;

	i = 0;
	while (i < tools->count_of_num - 1)
	{
		if (find_duplicates_helper(tools, i))
			return (1);
		if (i < tools->count_of_num)
			i++;
		else
			break ;
	}
	return (0);
}
