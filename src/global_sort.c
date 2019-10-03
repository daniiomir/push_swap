/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:21:58 by swarner           #+#    #+#             */
/*   Updated: 2019/10/03 21:17:11 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "operations.h"

int		find_place_in_a(int *stack, int len, int elem, char **rot_type)
{
	int		i;
	int		place;

	i = 0;
	place = 0;
	if (len == 2 && elem > stack[0] && elem < stack[1])
		place = 1;
	else if (len == 2 && elem < stack[0] && elem > stack[1])
		place = 0;
	else if (elem > stack[find_max_elem(stack, len)] || elem < stack[find_min_elem(stack, len)])
		place = find_min_elem(stack, len);
	else
		while (i < len)
		{
			if (elem > stack[i] && ((i + 1 < len && elem < stack[i + 1]) ||
									(i + 1 == len && elem < stack[0])))
			{
				place = i + 1;
				break ;
			}
			i++;
		}
	return (find_a_rot_type(len, place, rot_type));
}

static void	insert_back_in_a(t_tools *tools)
{
	int				num_of_rots;
	char			*rot_type;

	num_of_rots = 0;
	rot_type = ft_strnew(3);
	while (tools->size_b)
	{
		num_of_rots = find_place_in_a(tools->stack_a,
									  tools->size_a, tools->stack_b[0], &rot_type);
		while (num_of_rots > 0)
		{
			if (ft_strequ(rot_type, "ra"))
				operation(ra, tools);
			else
				operation(rra, tools);
			num_of_rots--;
		}
		operation(pa, tools);
	}
	place_smallest_first_a(tools);
	free(rot_type);
}

static void	insert_leftover_to_b(t_tools *tools)
{
	size_t idx;

	idx = 0;
	while (tools->size_a > 2)
	{
		idx = find_min_elem(tools->stack_a, tools->size_a);
		if (idx == 0)
			operation(pb, tools);
		else if (idx <= tools->size_a / 2)
			operation(ra, tools);
		else if (idx > tools->size_a / 2)
			operation(rra, tools);
	}
}

static void	process_moves(t_moves *best_move, t_tools *tools)
{
	while (best_move->a_moves)
	{
		if (ft_strequ(best_move->a_rot_type, "ra"))
			operation(ra, tools);
		else
			operation(rra, tools);
		best_move->a_moves--;
	}
	while (best_move->b_moves)
	{
		if (ft_strequ(best_move->b_rot_type, "rb"))
			operation(rb, tools);
		else
			operation(rrb, tools);
		best_move->b_moves--;
	}
}

void		global_sort(t_tools *tools)
{
	t_moves *best_move;
	size_t		optimizer;

	optimizer = (tools->size_a > 200)? 50 : 2;
	while (tools->size_b != 2)
		operation(pb, tools);
	while (tools->size_a > optimizer)
	{
		best_move = best_way_from_a_to_b(tools);
		while (best_move->common_moves)
		{
			if (ft_strequ(best_move->common_rot, "rr"))
				operation(rr, tools);
			else
				operation(rrr, tools);
			best_move->common_moves--;
		}
		process_moves(best_move, tools);
		operation(pb, tools);
		free_moves(best_move);
	}
	insert_leftover_to_b(tools);
	insert_back_in_a(tools);
}