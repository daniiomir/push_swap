/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:12:37 by swarner           #+#    #+#             */
/*   Updated: 2019/10/03 22:32:02 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

void	operation(void (*f)(t_tools *, int), t_tools *tools)
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

int		parse_options(char *param1, char *param2, t_tools *tools)
{
	int		for_arg;

	for_arg = 0;
	if (ft_strequ(param1, "-v"))
		tools->debug = 1;
	else if (ft_strequ(param1, "-c"))
		ft_error();
	if (ft_strequ(param2, "-c"))
		tools->color = 1;
	if (tools->debug && !tools->color)
		for_arg = 1;
	if (tools->debug && tools->color)
		for_arg = 2;
	return (for_arg);
}

void	free_moves(t_moves *moves)
{
	free(moves->a_rot_type);
	free(moves->b_rot_type);
	free(moves->common_rot);
	free(moves);
	moves = NULL;
}
