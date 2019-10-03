/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swarner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 21:11:56 by swarner           #+#    #+#             */
/*   Updated: 2019/10/03 21:11:58 by swarner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_a_rot_type(int len, int pos, char **a_rot_type)
{
	if (pos > len / 2)
	{
		*a_rot_type = ft_strcpy(*a_rot_type, "rra");
		if (len > 2)
			pos = len - pos;
	}
	else
		*a_rot_type = ft_strcpy(*a_rot_type, "ra");
	return (pos);
}

int		find_b_rot_type(int len, int pos, char **b_rot_type)
{
	if (pos > len / 2)
	{
		*b_rot_type = ft_strcpy(*b_rot_type, "rrb");
		if (len > 2)
			pos = len - pos;
	}
	else
		*b_rot_type = ft_strcpy(*b_rot_type, "rb");
	return (pos);
}
