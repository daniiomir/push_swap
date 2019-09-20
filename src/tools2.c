/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:12:37 by swarner           #+#    #+#             */
/*   Updated: 2019/09/19 19:43:29 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	is_sorted(t_tools *tools)
{
	size_t	i;

	i = 0;
	while (i < tools->count_of_num - 1)
	{
		if (tools->stack_a[i] > tools->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
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
	while (i < tools->size_b)
	{
		ft_putnbr(tools->stack_b[i++]);
		ft_putstr(" ");
	}
	ft_putstr("\n\n");
}