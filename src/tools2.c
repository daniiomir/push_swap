/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:12:37 by swarner           #+#    #+#             */
/*   Updated: 2019/09/24 15:18:30 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include "push_swap.h"
#include "operations.h"

int 	*create_stack(size_t size)
{
	int *stack;

	stack = (int *)malloc(sizeof(int) * size);
	return (stack);
}

size_t	is_sorted(t_tools *tools)
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
void 	operation(void (*f)(t_tools *, int), t_tools *tools)
{
	(*f)(tools, tools->is_visible);
	if (tools->debug)
		print_stacks(tools);
}

void	print_stacks(t_tools *tools)
{
	size_t	i;

	i = 0;
	ft_putstr("Stack A: ");
	while (i < tools->size_a)
	{
		ft_putnbr(tools->stack_a[i++]);
		ft_putstr(" ");
	}
	ft_putstr("\n");
	i = 0;
	ft_putstr("Stack B: ");
	if (tools->size_b && tools->stack_b)
	{
		while (i < tools->size_b)
		{
			ft_putnbr(tools->stack_b[i++]);
			ft_putstr(" ");
		}
	}
	ft_putstr("\n\n");
}

void	print_stacks_dbg(t_tools *tools, int *s1, int *s2)
{
	size_t	i;

	i = 0;
	ft_putstr("Stack A DEBUG: ");
	while (i < tools->size_a)
	{
		ft_putnbr(s1[i++]);
		ft_putstr(" ");
	}
	ft_putstr("\n");
	i = 0;
	ft_putstr("Stack B DEBUG: ");
	if (tools->size_b && s2)
	{
		while (i < tools->size_b)
		{
			ft_putnbr(s2[i++]);
			ft_putstr(" ");
		}
	}
	ft_putstr("\n\n");
}