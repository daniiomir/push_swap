/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:12:37 by swarner           #+#    #+#             */
/*   Updated: 2019/10/03 19:52:28 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (tools->debug && tools->color)
		ft_putstr("\x1b[32m");
	(*f)(tools, tools->is_visible);
	if (tools->debug && tools->color)
		ft_putstr("\x1b[0m");
	tools->op_count++;
	if (tools->debug && !tools->color)
		print_stacks(tools);
	else if (tools->debug && tools->color)
		print_stacks_color(tools);
}

void	print_stacks_color(t_tools *tools)
{
	size_t	i;

	i = 0;
	ft_putstr("\x1b[34mStack A: [ \x1b[0m");
	while (i < tools->size_a)
	{
		ft_putstr("\x1b[35m");
		ft_putnbr(tools->stack_a[i++]);
		ft_putstr("\x1b[0m ");
	}
	ft_putstr("\x1b[34m]\x1b[0m\n");
	i = 0;
	ft_putstr("\x1b[36mStack B: [\x1b[0m ");
	if (tools->size_b && tools->stack_b)
	{
		while (i < tools->size_b)
		{
			ft_putstr("\x1b[35m");
			ft_putnbr(tools->stack_b[i++]);
			ft_putstr("\x1b[0m ");
		}
	}
	else
		ft_putstr("\x1b[31mEmpty\x1b[0m ");
	ft_putstr("\x1b[36m]\x1b[0m\n\n");
}

void	print_stacks(t_tools *tools)
{
	size_t	i;

	i = 0;
	ft_putstr("Stack A:  ");
	while (i < tools->size_a)
	{
		ft_putnbr(tools->stack_a[i++]);
		ft_putstr(" ");
	}
	ft_putstr("\n");
	i = 0;
	ft_putstr("Stack B:  ");
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

void	free_moves(t_moves *moves)
{
	free(moves->a_rot_type);
	free(moves->b_rot_type);
	free(moves->common_rot);
	free(moves);
	moves = NULL;
}

//void	print_stacks_dbg(t_tools *tools, int *s1, int *s2)
//{
//	size_t	i;
//
//	i = 0;
//	ft_putstr("Stack A DEBUG: ");
//	while (i < tools->size_a)
//	{
//		ft_putnbr(s1[i++]);
//		ft_putstr(" ");
//	}
//	ft_putstr("\n");
//	i = 0;
//	ft_putstr("Stack B DEBUG: ");
//	if (tools->size_b && s2)
//	{
//		while (i < tools->size_b)
//		{
//			ft_putnbr(s2[i++]);
//			ft_putstr(" ");
//		}
//	}
//	ft_putstr("\n\n");
//}